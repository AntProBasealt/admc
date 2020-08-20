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

#ifndef CREATE_DIALOG_H
#define CREATE_DIALOG_H

#include "ad_interface.h"

#include <QString>
#include <QDialog>
#include <QList>
#include <QMap>

class QLineEdit;
class QVBoxLayout;
class QComboBox;
class QCheckBox;
class QGridLayout;

enum CreateType {
    CreateType_User,
    CreateType_Computer,
    CreateType_OU,
    CreateType_Group,
    CreateType_COUNT
};

// Create and open a create dialog appropriate for given type
void create_dialog(const QString &parent_dn, CreateType type, QWidget *parent);

/**
 * By default only has line edit for name and creates an object with
 * that name.
 * Subclass to add more widgets.
 * Then override apply_more_widgets() to apply changes from
 * those widgets after object is created.
 */
class CreateDialog : public QDialog {
Q_OBJECT

public:
    CreateDialog(const QString &parent_dn_arg, CreateType type_arg, QWidget *parent);

protected:
    QGridLayout *edits_layout;
    QLineEdit *name_edit;

private slots:
    void on_ok();
    
private:
    QString parent_dn;
    CreateType type;

    virtual QList<AdResult> apply_more_widgets(const QString &dn);
};

class CreateGroupDialog final : public CreateDialog {
Q_OBJECT

public:
    CreateGroupDialog(const QString &parent_dn_arg, CreateType type_arg, QWidget *parent);

private:
    QMap<QString, QLineEdit *> attributes;
    QComboBox *scope_combo;
    QComboBox *type_combo;

    QList<AdResult> apply_more_widgets(const QString &dn) override;
};

class CreateUserDialog final : public CreateDialog {
Q_OBJECT

public:
    CreateUserDialog(const QString &parent_dn_arg, CreateType type_arg, QWidget *parent);

private:
    QMap<QString, QLineEdit *> attributes;
    QMap<AccountOption, QCheckBox *> account_options;
    
    QList<AdResult> apply_more_widgets(const QString &dn) override;

    // QLineEdit *pass_edit;
    // QLineEdit *pass_confirm_edit;
};

QString create_type_to_string(const CreateType &type);

#endif /* CREATE_DIALOG_H */
