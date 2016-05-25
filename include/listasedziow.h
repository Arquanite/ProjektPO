#ifndef LISTASEDZIOW_H
#define LISTASEDZIOW_H

#include <QMap>

#include "sedziaglowny.h"
#include "sedziapomocniczy.h"

class ListaSedziow{
public:
    QMap<QString,SedziaGlowny> ListaSiatkowkaPlazowaGlowny;
    QMap<QString,SedziaPomocniczy> ListaSiatkowkaPlazowaPomocniczy;
    QMap<QString,SedziaGlowny> ListaPrzeciaganieLinyGlowny;
    QMap<QString,SedziaGlowny> ListaDwaOgnieGlowny;
};

#endif // LISTASEDZIOW_H
