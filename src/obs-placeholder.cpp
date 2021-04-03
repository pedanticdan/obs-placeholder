#include <obs-module.h>
#include <obs-frontend-api.h>
#include <obs-data.h>

#include <QtCore/QTimer>
#include <QtWidgets/QAction>
#include <QtWidgets/QMainWindow>
#include "obs-placeholder.h"
#include "forms/dialog.h"

/* Defines common functions (required) */
OBS_DECLARE_MODULE()

/* Implements common ini-based locale (optional) */
OBS_MODULE_USE_DEFAULT_LOCALE("obs-placeholder", "en-US")


bool obs_module_load(void)
{
	blog(LOG_INFO, "entering obs_module_load");
	obs_frontend_push_ui_translation(obs_module_get_string);
	QMainWindow* mainWindow = (QMainWindow*)obs_frontend_get_main_window();
	Dialog* settingsDialog = new Dialog(mainWindow);
	obs_frontend_pop_ui_translation();
	const char* menuActionText =
		obs_module_text("Placeholder.Settings.MenuTitle");
	QAction* menuAction =
		(QAction*)obs_frontend_add_tools_menu_qaction(menuActionText);
	QObject::connect(menuAction, &QAction::triggered, [settingsDialog] {
		settingsDialog->show();
    });

	blog(LOG_INFO, "exiting obs_module_load");
	return true;
}
