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

    void browse();
    void savePlaceholder();

private:
	Ui::Dialog *ui;
};
#endif // DIALOG_H
