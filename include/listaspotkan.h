#ifndef LISTASPOTKAN_H
#define LISTASPOTKAN_H

#include <QList>
#include <QDataStream>

#include "siatkowkaplazowa.h"
#include "przeciaganieliny.h"
#include "dwaognie.h"

class ListaSpotkan {
public:
    QList<SiatkowkaPlazowa> ListaSiatkowkaPlazowa;
    QList<PrzeciaganieLiny> ListaPrzeciaganieLiny;
    QList<DwaOgnie> ListaDwaOgnie;

    friend QDataStream &operator<<(QDataStream &out, const ListaSpotkan &L);
    friend QDataStream &operator>>(QDataStream &in, ListaSpotkan &L);
};

#endif // LISTASPOTKAN_H
