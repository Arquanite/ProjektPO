#ifndef SEDZIAGLOWNY_H
#define SEDZIAGLOWNY_H

#include "sedzia.h"

class SedziaGlowny : public Sedzia {
public:
    SedziaGlowny(QString Imie, QString Nazwisko);
    SedziaGlowny(const Osoba &O);
};

#endif // SEDZIAGLOWNY_H
