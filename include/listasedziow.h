#ifndef LISTASEDZIOW_H
#define LISTASEDZIOW_H

#include <QList>

#include "sedziaglowny.h"
#include "sedziapomocniczy.h"

class ListaSedziow{
public:
    QList<SedziaGlowny> ListaSiatkowkaPlazowaGlowny;
    QList<SedziaGlowny> ListaSiatkowkaPlazowaPomocniczy;
    QList<SedziaGlowny> ListaPrzeciaganieLinyGlowny;
    QList<SedziaGlowny> ListaDwaOgnieGlowny;
};

#endif // LISTASEDZIOW_H
