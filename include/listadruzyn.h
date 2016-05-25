#ifndef LISTADRUZYN_H
#define LISTADRUZYN_H

#include <QList>

#include "druzyna.h"

class ListaDruzyn{
public:
    QList<Druzyna> ListaSiatkowkaPlazowa;
    QList<Druzyna> ListaPrzeciaganieLiny;
    QList<Druzyna> ListaDwaOgnie;
};

#endif // LISTADRUZYN_H
