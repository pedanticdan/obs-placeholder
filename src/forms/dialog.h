#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <util/config-file.h>
#include <util/platform.h>
#include "ui_dialog.h"
#include <obs-frontend-api.h>

#if defined(_WIN32) || defined(_WIN64)
#define PLACEHOLDER_DIR "\\obs-studio\\plugin_config\\win-dshow"
#define PLACEHOLDER_PNG "\\obs-studio\\plugin_config\\win-dshow\\placeholder.png"
#endif
#if defined(__APPLE__)
#define PLACEHOLDER_DIR "obs-studio/plugin_config/mac-virtualcam"
#define PLACEHOLDER_PNG "obs-studio/plugin_config/mac-virtualcam/placeholder.png"
#endif

#define SECTION_NAME "PlaceHolder"
#define PARAM_PNG "PNGFile"

#define blog(level, msg, ...) blog(level, "[obs-placeholder] " msg, ##__VA_ARGS__)


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void showEvent(QShowEvent* event);
    void browse();
    void savePlaceholder();

private:
	Ui::Dialog *ui;
};
#endif // DIALOG_H
