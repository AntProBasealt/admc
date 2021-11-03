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

#ifndef FILTER_CLASSES_WIDGET_H
#define FILTER_CLASSES_WIDGET_H

/**
 * This widget is embedded in FilterDialog. Contains
 * checkboxes of object classes. get_filter() returns a
 * filter which will filter out unselected classes.
 */

#include <QWidget>

class QCheckBox;
class AdConfig;

namespace Ui {
class FilterClassesWidget;
}

class FilterClassesWidget final : public QWidget {
    Q_OBJECT

public:
    Ui::FilterClassesWidget *ui;

    FilterClassesWidget(QWidget *parent = nullptr);
    ~FilterClassesWidget();

    // Initializes by adding checkbox for all possible
    // filter classes
    void init(AdConfig *adconfig);

    // Sets available classes and default selected classes.
    // All given classes must be part of "filter_classes".
    // TODO: above line is bad, not sure if should pass a
    // class list to init as well?
    void set_classes(const QList<QString> &class_list, const QList<QString> &selected_list);

    QString get_filter() const;
    QList<QString> get_selected_classes() const;
    QList<QString> get_selected_classes_display() const;
    QVariant save_state() const;
    void restore_state(const QVariant &state);

private:
    QHash<QString, QCheckBox *> checkbox_map;

    void clear_selection();
    void select_all();
};

#endif /* FILTER_CLASSES_WIDGET_H */
