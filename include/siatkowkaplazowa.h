#ifndef SIATKOWKAPLAZOWA_H
#define SIATKOWKAPLAZOWA_H

#include "siatkowka.h"

class SiatkowkaPlazowa : public Siatkowka {
public:
    SiatkowkaPlazowa(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia, SedziaPomocniczy SedziaPomocniczy1, SedziaPomocniczy SedziaPomocniczy2);
    virtual bool Rozegraj();
};

#endif // SIATKOWKAPLAZOWA_H
