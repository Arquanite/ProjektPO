#ifndef MECZ_H
#define MECZ_H

#include <QString>

#include "sedziaglowny.h"

/**
 * @brief Abstrakcyjna klasa reprezentująca mecz.
 *
 * Jak w normalnym życiu, w meczu jest sędzia, gospodarz i gość.
 * Mogą oni zdobywać punkty, mecz może zostać rozegrany automatycznie.
 * Klasa ta operuje na nazwach, a nie na obiektach celem oszczędzania pamięci
 * i zachowania spójności danych.
 *
 */
class Mecz {
protected:
    int m_PunktyGospodarza = 0;
    int m_PunktyGoscia = 0;
    QString m_Sedzia;
public:
    Mecz(); ///< Konstruktor domyślny, nie należy go używać.
    Mecz(QString Sedzia); ///< Konstruktor.
    virtual ~Mecz(); ///< Destruktor wirtualny.
    int PunktyGospodarza() const; ///< Zwraca punkty zdobyte przez gospodarza.
    int PunktyGoscia() const; ///< Zwraca punkty zdobyte przez gościa.
    virtual QString Rozegraj() = 0; ///< Metoda czysto wirtualna, jej zadaniem jest losowanie wyniku charakterystycznego dla określonej konkurencji.
    QString Wynik() const; ///< Zwraca wynik w postaci czytelnej dla człowieka np. 1:3.
    void WpiszWynik(int PunktyGospodarza, int PunktyGoscia); ///< Pozwala na ręczne ustawienie wyniku meczu.
    QString Sedzia() const; ///< Zwraca nazwę sędziego.
};

#endif // MECZ_H

