#ifndef ZAWODNIK_H
#define ZAWODNIK_H

#include <QDataStream>

#include "osoba.h"

class Zawodnik : public Osoba {
public:
    Zawodnik(QString Imie, QString Nazwisko);
    Zawodnik(const Osoba &O);
    Zawodnik();

    friend QDataStream &operator<<(QDataStream &out, const Zawodnik &Z);
    friend QDataStream &operator>>(QDataStream &in, Zawodnik &Z);
};

#endif // ZAWODNIK_H
