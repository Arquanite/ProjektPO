#ifndef LISTASEDZIOW_H
#define LISTASEDZIOW_H

#include <QList>

#include "sedziaglowny.h"
#include "sedziapomocniczy.h"

class ListaSedziow{
public:
    QList<Sedzia> ListaSiatkowkaPlazowaGlowny;
    QList<Sedzia> ListaSiatkowkaPlazowaPomocniczy;
    QList<Sedzia> ListaPrzeciaganieLinyGlowny;
    QList<Sedzia> ListaDwaOgnieGlowny;
};

#endif // LISTASEDZIOW_H
