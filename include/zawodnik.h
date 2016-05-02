#ifndef ZAWODNIK_H
#define ZAWODNIK_H

#include "osoba.h"

class Zawodnik : public Osoba {
public:
    Zawodnik(QString Imie, QString Nazwisko);
    Zawodnik(const Osoba &O);
};

#endif // ZAWODNIK_H
