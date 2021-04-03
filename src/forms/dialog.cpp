#include "dialog.h"

#include <obs-module.h>
#include <QtWidgets/QMessageBox>

#include "../obs-placeholder.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QAbstractButton::clicked, this, &Dialog::browse);
    connect(ui->saveButton, &QAbstractButton::clicked, this, &Dialog::savePlaceholder);

	blog(LOG_INFO, "Get config");

	obsConfig = obs_frontend_get_profile_config();

	blog(LOG_INFO, "Get path to custom png");
	const char *png = config_get_string(obsConfig, SECTION_NAME, PARAM_PNG);

	blog(LOG_INFO, "Set text to custom png");
	ui->lineEdit->setText(QString(png));
}

void Dialog::savePlaceholder()
{
	blog(LOG_INFO, "savePlaceholder");
	std::string str = ui->lineEdit->text().toStdString();
	const char *fileName = str.c_str();
	config_set_string(obsConfig, SECTION_NAME, PARAM_PNG, fileName);
	char *custom = os_get_config_path_ptr(PLACEHOLDER_DIR);
	int ret;
	if (!os_file_exists(custom))
		os_mkdirs(custom);
	bfree(custom);
	custom = os_get_config_path_ptr(PLACEHOLDER_PNG);
	if (os_file_exists(fileName)) {
		if (os_file_exists(custom))
			ret = os_unlink(custom);
		ret = os_copyfile(fileName, custom);
	} else {
		if (strlen(fileName) == 0)
			ret = os_unlink(custom);
	}
	bfree(custom);
}

void Dialog::browse()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select PNG File"),"/path/to/file/",tr("PNG File (*.png)"));
    ui->lineEdit->setText(fileName);
}

Dialog::~Dialog()
{
    delete ui;
}


