
#ifndef AD_INTERFACE_H
#define AD_INTERFACE_H

#include <QList>
#include <QString>
#include <QMap>

// Interface functions to convert from raw char** active directory returns to Qt containers
// Also can load fake data if program is run with "fake" option

extern bool FAKE_AD; 

bool ad_interface_login();
QList<QString> load_children(QString &dn);
QMap<QString, QList<QString>> load_attributes(QString &dn);
bool set_attribute(QString &dn, QString &attribute, QString &value);

#endif /* AD_INTERFACE_H */