#include "listaspotkan.h"

QDataStream &operator<<(QDataStream &out, const ListaSpotkan &L){
    out<<L.ListaSiatkowkaPlazowa<<L.ListaPrzeciaganieLiny<<L.ListaDwaOgnie;
    return out;
}

QDataStream &operator>>(QDataStream &in, ListaSpotkan &L){
    in>>L.ListaSiatkowkaPlazowa>>L.ListaPrzeciaganieLiny>>L.ListaDwaOgnie;
    return in;
}
