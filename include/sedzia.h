#ifndef SEDZIA_H
#define SEDZIA_H

#include "osoba.h"

class Sedzia : public Osoba {
public:
    Sedzia(QString Imie, QString Nazwisko);
    Sedzia(const Osoba &O);
    Sedzia();
};

#endif // SEDZIA_H
