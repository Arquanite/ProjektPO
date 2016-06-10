#ifndef SIATKOWKAPLAZOWA_H
#define SIATKOWKAPLAZOWA_H

#include <QDataStream>
#include "siatkowka.h"

class SiatkowkaPlazowa : public Siatkowka {
public:
    SiatkowkaPlazowa();
    SiatkowkaPlazowa(QString Gospodarz, QString Gosc, QString Sedzia, QString SedziaPomocniczy1, QString SedziaPomocniczy2);
    virtual QString Rozegraj() override;

    friend QDataStream &operator<<(QDataStream &out, const SiatkowkaPlazowa &P);
    friend QDataStream &operator>>(QDataStream &in, SiatkowkaPlazowa &P);
};

#endif // SIATKOWKAPLAZOWA_H
