#ifndef LISTASPOTKAN_H
#define LISTASPOTKAN_H

#include <QList>

#include "siatkowkaplazowa.h"
#include "przeciaganieliny.h"
#include "dwaognie.h"

class ListaSpotkan {
public:
    QList<SiatkowkaPlazowa> ListaSiatkowkaPlazowa;
    QList<PrzeciaganieLiny> ListaPrzeciaganieLiny;
    QList<DwaOgnie> ListaDwaOgnie;
};

#endif // LISTASPOTKAN_H
