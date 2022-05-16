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

#ifndef POLICY_OU_IMPL_H
#define POLICY_OU_IMPL_H

#include "console_widget/console_impl.h"
#include "console_widget/console_widget.h"

class PolicyOUImpl final : public ConsoleImpl {
    Q_OBJECT

public:
    PolicyOUImpl(ConsoleWidget *console_arg);

    void fetch(const QModelIndex &index) override;
    void refresh(const QList<QModelIndex> &index_list) override;

    QSet<StandardAction> get_standard_actions(const QModelIndex &index, const bool single_selection) const override;

    QList<QString> column_labels() const override;
    QList<int> default_columns() const override;
};

#endif /* POLICY_OU_IMPL_H */
