#ifndef SIATKOWKA_H
#define SIATKOWKA_H

#include "pilka.h"
#include "sedziapomocniczy.h"

class Siatkowka : public Pilka {
private:
    SedziaPomocniczy m_SedziaPomocniczy1;
    SedziaPomocniczy m_SedziaPomocniczy2;
public:
    Siatkowka(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia, SedziaPomocniczy SedziaPomocniczy1, SedziaPomocniczy SedziaPomocniczy2);
    SedziaPomocniczy SedziaPomocniczy1() const;
    SedziaPomocniczy SedziaPomocniczy2() const;
    virtual bool Rozegraj();
};

#endif // SIATKOWKA_H
