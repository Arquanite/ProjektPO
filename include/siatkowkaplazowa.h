#ifndef SIATKOWKAPLAZOWA_H
#define SIATKOWKAPLAZOWA_H

#include "siatkowka.h"

class SiatkowkaPlazowa : public Siatkowka {
public:
    SiatkowkaPlazowa(QString Gospodarz, QString Gosc, QString Sedzia, QString SedziaPomocniczy1, QString SedziaPomocniczy2);
    virtual QString Rozegraj() override;
};

#endif // SIATKOWKAPLAZOWA_H
