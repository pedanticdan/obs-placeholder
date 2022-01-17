/*
obs-placeholder

    OBS Studio Plugin to simplify changing the Virtual Camera's placeholder.png
    file.
    Copyright (C) 2021  Dan Campbell

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <obs.h>
#include <obs-data.h>
#include <obs-frontend-api.h>
#include <obs-module.h>

#include "forms/dialog.h"
#include "obs-placeholder.h"
#include <QtCore/QTimer>
#include <QtWidgets/QAction>
#include <QtWidgets/QMainWindow>

/* Defines common functions (required) */
OBS_DECLARE_MODULE()

/* Implements common ini-based locale (optional) */
OBS_MODULE_USE_DEFAULT_LOCALE("obs-placeholder", "en-US")

static void profile_changed(enum obs_frontend_event event,
  void *) {
  if (event == OBS_FRONTEND_EVENT_PROFILE_CHANGED) {
    blog(LOG_INFO, "obs-placeholder OBS_FRONTEND_EVENT_PROFILE_CHANGED");
    config_t *obsConfig = obs_frontend_get_profile_config();

    const char *png = config_get_string(obsConfig, SECTION_NAME, PARAM_PNG);
    blog(LOG_INFO, "obs-placeholder path to custom png '%s'", png);
    char *custom = os_get_config_path_ptr(PLACEHOLDER_DIR);
    blog(LOG_INFO, "obs-placeholder path to placeholder dir '%s'", custom);

    int ret;
    if (!os_file_exists(custom))
      os_mkdirs(custom);
    bfree(custom);
    blog(LOG_INFO, "obs-placeholder make sure dir exists [%s]", custom);
    custom = os_get_config_path_ptr(PLACEHOLDER_PNG);
    blog(LOG_INFO, "obs-placeholder get file path [%s]", custom);
    if (png != NULL && os_file_exists(png)) {
      blog(LOG_INFO, "obs-placeholder exists [%s]", png);
      if (os_file_exists(custom)) {
        blog(LOG_INFO, "obs-placeholder exists [%s]", custom);
        ret = os_unlink(custom);
      }
      blog(LOG_INFO, "obs-placeholder copy [%s] to [%s]", png, custom);
      ret = os_copyfile(png, custom);
    } else {
      blog(LOG_INFO, "obs-placeholder does not exist or not configured");
      blog(LOG_INFO, "obs-placeholder unlink [%s]", custom);
      ret = os_unlink(custom);
    }
    bfree(custom);
  }
}

bool obs_module_load(void) {
  blog(LOG_INFO, "entering obs_module_load");
  obs_data_t *obsData = obs_get_private_data();
  bool vcamEnabled = obs_data_get_bool(obsData, "vcamEnabled");
  if (vcamEnabled) {
    obs_frontend_push_ui_translation(obs_module_get_string);
    QMainWindow *mainWindow = (QMainWindow *)obs_frontend_get_main_window();
    Dialog *settingsDialog = new Dialog(mainWindow);
    obs_frontend_pop_ui_translation();
    const char *menuActionText =
        obs_module_text("Placeholder.Settings.MenuTitle");
    QAction *menuAction =
        (QAction *)obs_frontend_add_tools_menu_qaction(menuActionText);
    QObject::connect(menuAction, &QAction::triggered,
                   [settingsDialog] { settingsDialog->show(); });
    obs_frontend_add_event_callback(profile_changed, nullptr);

  }
  blog(LOG_INFO, "exiting obs_module_load");
  return true;
}
