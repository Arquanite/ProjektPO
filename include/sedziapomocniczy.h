#ifndef SEDZIAPOMOCNICZY_H
#define SEDZIAPOMOCNICZY_H

#include <QDataStream>

#include "sedzia.h"

class SedziaPomocniczy : public Sedzia {
public:
    SedziaPomocniczy(QString Imie, QString Nazwisko);
    SedziaPomocniczy(const Osoba &O);
    SedziaPomocniczy();

    friend QDataStream &operator<<(QDataStream &out, const SedziaPomocniczy &S);
    friend QDataStream &operator>>(QDataStream &in, SedziaPomocniczy &S);
};

#endif // SEDZIAPOMOCNICZY_H
