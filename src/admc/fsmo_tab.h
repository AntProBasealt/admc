/*
 * ADMC - AD Management Center
 *
 * Copyright (C) 2020-2022 BaseALT Ltd.
 * Copyright (C) 2020-2022 Dmitry Degtyarev
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

#ifndef FSMO_TAB_H
#define FSMO_TAB_H

#include <QWidget>

class AdInterface;

namespace Ui {
class FSMOTab;
}

class FSMOTab final : public QWidget {
    Q_OBJECT

public:
    Ui::FSMOTab *ui;

    FSMOTab(const QString &title, const QString &role_dn);
    ~FSMOTab();

    void load(AdInterface &ad);

private:
    QString role_dn;

    void change_master();
};

#endif /* FSMO_TAB_H */
