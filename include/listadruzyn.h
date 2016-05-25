#ifndef LISTADRUZYN_H
#define LISTADRUZYN_H

#include <QMap>

#include "druzyna.h"

class ListaDruzyn{
public:
    QMap<QString,Druzyna> ListaSiatkowkaPlazowa;
    QMap<QString,Druzyna> ListaPrzeciaganieLiny;
    QMap<QString,Druzyna> ListaDwaOgnie;
};

#endif // LISTADRUZYN_H
