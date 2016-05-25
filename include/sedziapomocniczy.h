#ifndef SEDZIAPOMOCNICZY_H
#define SEDZIAPOMOCNICZY_H

#include "sedzia.h"

class SedziaPomocniczy : public Sedzia {
public:
    SedziaPomocniczy(QString Imie, QString Nazwisko);
    SedziaPomocniczy(const Osoba &O);
    SedziaPomocniczy();
};

#endif // SEDZIAPOMOCNICZY_H
