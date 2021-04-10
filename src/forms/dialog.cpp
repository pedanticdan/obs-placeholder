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
	QString newTitle = this->windowTitle() + " v" + OBS_PLACEHOLDER_VERSION;

	this->setWindowTitle(newTitle);

	blog(LOG_INFO, "Get config");

	config_t *obsConfig = obs_frontend_get_profile_config();

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
	blog(LOG_INFO, "get text from widget [%s]", fileName);
	config_t *obsConfig = obs_frontend_get_profile_config();
	config_set_string(obsConfig, SECTION_NAME, PARAM_PNG, fileName);
	blog(LOG_INFO, "set text in config [%s][%s]", SECTION_NAME, PARAM_PNG);
	char *custom = os_get_config_path_ptr(PLACEHOLDER_DIR);
	int ret;
	if (!os_file_exists(custom))
		os_mkdirs(custom);
	bfree(custom);
	blog(LOG_INFO, "make sure dir exists [%s]", custom);
	custom = os_get_config_path_ptr(PLACEHOLDER_PNG);
	blog(LOG_INFO, "get file path [%s]", custom);
	if (os_file_exists(fileName)) {
		if (os_file_exists(custom))
			ret = os_unlink(custom);
		ret = os_copyfile(fileName, custom);
	} else {
		if (strlen(fileName) == 0)
			ret = os_unlink(custom);
	}
	bfree(custom);
	config_save(obsConfig);
	blog(LOG_INFO, "exit savePlaceholder");
}

void Dialog::showEvent(QShowEvent* event) {
	config_t *obsConfig = obs_frontend_get_profile_config();
	const char *png = config_get_string(obsConfig, SECTION_NAME, PARAM_PNG);
	ui->lineEdit->setText(png);
}


void Dialog::browse()
{
	config_t *obsConfig = obs_frontend_get_profile_config();
	const char *png = config_get_string(obsConfig, SECTION_NAME, PARAM_PNG);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select PNG File"),png,tr("PNG File (*.png)"));
	if (fileName.length() == 0) {
    	ui->lineEdit->setText(png);
	} else {
    	ui->lineEdit->setText(fileName);
	}

}

Dialog::~Dialog()
{
    delete ui;
}


