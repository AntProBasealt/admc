/*
 * ADMC - AD Management Center
 *
 * Copyright (C) 2020 BaseALT Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main_window.h"
#include "menubar.h"
#include "properties_dialog.h"
#include "status.h"
#include "settings.h"
#include "policies_widget.h"
#include "ad_interface.h"
#include "ad_config.h"
#include "object_model.h"
#include "filter_dialog.h"
#include "object_menu.h"
#include "console.h"
#include "utils.h"

#include <QApplication>
#include <QString>
#include <QSplitter>
#include <QStatusBar>
#include <QTextEdit>
#include <QAction>
#include <QDesktopWidget>

MainWindow::MainWindow()
: QMainWindow()
{
    if (SETTINGS()->contains_variant(VariantSetting_MainWindowGeometry)) {
        SETTINGS()->restore_geometry(this, VariantSetting_MainWindowGeometry);
    } else {
        // Make window 70% of desktop size for first startup
        resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    }

    // Setup menubar, status bar and a dummy central widget
    // for display in offline state
    menubar = new MenuBar();
    setMenuBar(menubar);

    QStatusBar *status_bar = STATUS()->status_bar;
    setStatusBar(status_bar);

    STATUS()->status_bar->showMessage(tr("Ready"));
    SETTINGS()->connect_toggle_widget(STATUS()->status_log, BoolSetting_ShowStatusLog);

    console = new Console(menubar);

    auto vert_splitter = new QSplitter(Qt::Vertical);
    vert_splitter->addWidget(STATUS()->status_log);
    vert_splitter->addWidget(console);
    vert_splitter->setStretchFactor(0, 1);
    vert_splitter->setStretchFactor(1, 3);

    setCentralWidget(vert_splitter);

    connect(
        menubar->filter_action, &QAction::triggered,
        console, &Console::open_filter_dialog);
    connect(
        menubar->connect_action, &QAction::triggered,
        this, &MainWindow::connect_to_server);

    connect_to_server();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    SETTINGS()->save_geometry(this, VariantSetting_MainWindowGeometry);

    QApplication::quit();
}

void MainWindow::connect_to_server() {
    AdInterface ad;
    if (ad_connected(ad)) {
        // TODO: check for load failure
        ADCONFIG()->load(ad);

        STATUS()->display_ad_messages(ad, this);

        menubar->go_online();
        console->go_online(ad);
    }
}
