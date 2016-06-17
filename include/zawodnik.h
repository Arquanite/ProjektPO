#ifndef ZAWODNIK_H
#define ZAWODNIK_H

#include <QDataStream>

#include "osoba.h"

/**
 * @brief Klasa reprezentująca zawodnika.
 *
 * @see Sedzia
 */
class Zawodnik : public Osoba {
public:
    Zawodnik(QString Imie, QString Nazwisko); ///< Konstruktor, nadaje zawodnikowi imię i nazwisko.
    Zawodnik(const Osoba &O); ///< Dodaje konwersję z klasy Osoba.
    Zawodnik(); ///< Konstruktor domyślny, nie należy go używać.

    friend QDataStream &operator<<(QDataStream &out, const Zawodnik &Z); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, Zawodnik &Z); ///< Umożliwia deserializację.
};

#endif // ZAWODNIK_H
