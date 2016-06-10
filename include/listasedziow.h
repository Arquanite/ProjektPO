#ifndef LISTASEDZIOW_H
#define LISTASEDZIOW_H

#include <QMap>
#include <QDataStream>

#include "sedziaglowny.h"
#include "sedziapomocniczy.h"

class ListaSedziow{
public:
    QMap<QString,SedziaGlowny> ListaSiatkowkaPlazowaGlowny;
    QMap<QString,SedziaPomocniczy> ListaSiatkowkaPlazowaPomocniczy;
    QMap<QString,SedziaGlowny> ListaPrzeciaganieLinyGlowny;
    QMap<QString,SedziaGlowny> ListaDwaOgnieGlowny;

    friend QDataStream &operator<<(QDataStream &out, const ListaSedziow &L);
    friend QDataStream &operator>>(QDataStream &in, ListaSedziow &L);
};

#endif // LISTASEDZIOW_H
