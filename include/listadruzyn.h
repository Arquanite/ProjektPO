#ifndef LISTADRUZYN_H
#define LISTADRUZYN_H

#include <QDataStream>
#include <QMap>

#include "druzyna.h"

class ListaDruzyn{
public:
    QMap<QString,Druzyna> ListaSiatkowkaPlazowa;
    QMap<QString,Druzyna> ListaPrzeciaganieLiny;
    QMap<QString,Druzyna> ListaDwaOgnie;

    friend QDataStream &operator<<(QDataStream &out, const ListaDruzyn &L);
    friend QDataStream &operator>>(QDataStream &in, ListaDruzyn &L);
};

#endif // LISTADRUZYN_H
