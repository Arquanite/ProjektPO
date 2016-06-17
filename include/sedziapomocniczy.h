#ifndef SEDZIAPOMOCNICZY_H
#define SEDZIAPOMOCNICZY_H

#include <QDataStream>

#include "sedzia.h"

/**
 * @brief Klasa reprezentująca sędziego pomocniczego.
 *
 * @see SedziaGlowny
 */
class SedziaPomocniczy : public Sedzia {
public:
    SedziaPomocniczy(QString Imie, QString Nazwisko); ///< Konstruktor, nadaje sędziemu imię i nazwisko.
    SedziaPomocniczy(const Osoba &O); ///< Dodaje konwersję z klasy Osoba.
    SedziaPomocniczy(); ///< Konstruktor domyślny, nie należy go używać.

    friend QDataStream &operator<<(QDataStream &out, const SedziaPomocniczy &S); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, SedziaPomocniczy &S); ///< Umożliwia deserializację.
};

#endif // SEDZIAPOMOCNICZY_H
