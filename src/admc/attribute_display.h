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
#ifndef ATTRIBUTE_DISPLAY_H
#define ATTRIBUTE_DISPLAY_H

#include <QString>
#include <QByteArray>

const qint64 MILLIS_TO_100_NANOS = 10000LL;
const qint64 SECONDS_TO_MILLIS   = 1000LL;
const qint64 MINUTES_TO_SECONDS  = 60LL;
const qint64 HOURS_TO_SECONDS    = MINUTES_TO_SECONDS * 60LL;
const qint64 DAYS_TO_SECONDS     = HOURS_TO_SECONDS * 24LL;

QString attribute_display_value(const QString &attribute, const QByteArray &value);
QString attribute_display_values(const QString &attribute, const QList<QByteArray> &values);

QString object_sid_to_display_value(const QByteArray &bytes);
QString octet_to_display_value(const QByteArray &bytes);

#endif /* ATTRIBUTE_DISPLAY_H */
