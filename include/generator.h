#ifndef GENERATOR_H
#define GENERATOR_H

#include <QStringList>
#include <QFile>
#include <QTextStream>

#include "osoba.h"
#include "druzyna.h"

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
    Generator();

    Osoba GenerujKobiete();
    Osoba GenerujMezczyzne();

    Osoba GenerujOsobe();
    QString GenerujNazwe();

    Druzyna GenerujDruzyne(int LiczbaOsob);
};

#endif // GENERATOR_H
