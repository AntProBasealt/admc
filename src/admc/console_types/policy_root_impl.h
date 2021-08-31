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

#ifndef POLICY_ROOT_IMPL_H
#define POLICY_ROOT_IMPL_H

#include "central_widget.h"
#include "console_widget/console_widget.h"
#include "console_widget/console_impl.h"

class QStandardItem;
class AdObject;
class AdInterface;
class ConsoleActions;
class PolicyResultsWidget;
class CreatePolicyDialog;
template <typename T>
class QList;

QList<QString> console_policy_header_labels();
QList<int> console_policy_default_columns();
void console_policy_tree_init(ConsoleWidget *console, AdInterface &ad);

class PolicyRootImpl final : public ConsoleImpl {
    Q_OBJECT

public:
    PolicyRootImpl(ConsoleWidget *console_arg);

    void fetch(const QModelIndex &index) override;
    void refresh(const QList<QModelIndex> &index_list) override;

    QList<QAction *> get_all_custom_actions() const override;
    QSet<QAction *> get_custom_actions(const QModelIndex &index, const bool single_selection) const override;
    QSet<StandardAction> get_standard_actions(const QModelIndex &index, const bool single_selection) const override;

private:
    QAction *create_policy_action;
    CreatePolicyDialog *create_policy_dialog;

    void on_dialog_created_policy(const QString &dn);
    void create_policy_in_console(const AdObject &object);
};

#endif /* POLICY_ROOT_IMPL_H */
