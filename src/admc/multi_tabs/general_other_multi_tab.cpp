/*
 * ADMC - AD Management Center
 *
 * Copyright (C) 2020-2021 BaseALT Ltd.
 * Copyright (C) 2020-2021 Dmitry Degtyarev
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

#include "multi_tabs/general_other_multi_tab.h"
#include "multi_tabs/ui_general_other_multi_tab.h"

#include "ad_defines.h"
#include "attribute_multi_edits/string_multi_edit.h"

GeneralOtherMultiTab::GeneralOtherMultiTab(QList<AttributeMultiEdit *> *edit_list, QWidget *parent)
: QWidget(parent) {
    ui = new Ui::GeneralOtherMultiTab();
    ui->setupUi(this);

    new StringMultiEdit(ui->description_edit, ui->description_check, ATTRIBUTE_DESCRIPTION, edit_list, this);
}
