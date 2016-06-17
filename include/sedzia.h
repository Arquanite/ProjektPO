#ifndef SEDZIA_H
#define SEDZIA_H

#include "osoba.h"
/**
 * @brief Klasa reprezentująca sędziego.
 *
 * @see Zawodnik
 */
class Sedzia : public Osoba {
public:
    Sedzia(QString Imie, QString Nazwisko); ///< Konstruktor, nadaje sędziemu imię i nazwisko.
    Sedzia(const Osoba &O); ///< Dodaje konwersję z klasy Osoba.
    Sedzia(); ///< Konstruktor domyślny, nie należy go używać.
};

#endif // SEDZIA_H
