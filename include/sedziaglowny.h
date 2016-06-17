#ifndef SEDZIAGLOWNY_H
#define SEDZIAGLOWNY_H

#include <QDataStream>

#include "sedzia.h"

/**
 * @brief Klasa reprezentująca sędziego głównego.
 *
 * @see SedziaPomocniczy
 */
class SedziaGlowny : public Sedzia {
public:
    SedziaGlowny(QString Imie, QString Nazwisko); ///< Konstruktor, nadaje sędziemu imię i nazwisko.
    SedziaGlowny(const Osoba &O); ///< Dodaje konwersję z klasy Osoba.
    SedziaGlowny(); ///< Konstruktor domyślny, nie należy go używać.

    friend QDataStream &operator<<(QDataStream &out, const SedziaGlowny &S); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, SedziaGlowny &S); ///< Umożliwia deserializację.
};

#endif // SEDZIAGLOWNY_H
