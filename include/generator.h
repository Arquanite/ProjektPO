#ifndef GENERATOR_H
#define GENERATOR_H

#include <QStringList>
#include <QFile>
#include <QTextStream>

#include "osoba.h"
#include "druzyna.h"

/**
 * @brief Klasa odpowiedzialna za tworzenie losowych osób, drużyn i nazw.
 *
 * Generator potrafi wygenerować około 2 000 000 unikalnych osób, generuje zarówno mężczyzn jak i kobiety.
 * Potrafi też za pomocą autorskiego algorytmu generować nazwy drużyn. Łącząc te dwie funkcjonalności generuje drużyny.
 */
class Generator{
private:
    QStringList ImionaM;
    QStringList ImionaZ;
    QStringList NazwiskaM;
    QStringList NazwiskaZ;

    QStringList Przymiotniki;
    QStringList Rzeczowniki;
    QStringList TeTrzecie;

public:
    Generator(); ///< Konstruktor.

    Osoba GenerujKobiete(); ///< Zwraca osobę o żeńskim imieniu i nazwisku.
    Osoba GenerujMezczyzne(); ///< Zwraca osobę o męskim imieniu i nazwisku.

    Osoba GenerujOsobe(); ///< Generuje losowo kobietę lub mężczyznę.
    QString GenerujNazwe(); ///< Generuje nazwę drużyny.

    Druzyna GenerujDruzyne(int LiczbaOsob); ///< Generuje drużynę o losowej nazwie i określonej liczbie losowych zawodników.
};

#endif // GENERATOR_H
