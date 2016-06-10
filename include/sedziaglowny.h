#ifndef SEDZIAGLOWNY_H
#define SEDZIAGLOWNY_H

#include <QDataStream>

#include "sedzia.h"

class SedziaGlowny : public Sedzia {
public:
    SedziaGlowny(QString Imie, QString Nazwisko);
    SedziaGlowny(const Osoba &O);
    SedziaGlowny();

    friend QDataStream &operator<<(QDataStream &out, const SedziaGlowny &S);
    friend QDataStream &operator>>(QDataStream &in, SedziaGlowny &S);
};

#endif // SEDZIAGLOWNY_H
