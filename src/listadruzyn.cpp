#include "listadruzyn.h"

QDataStream &operator<<(QDataStream &out, const ListaDruzyn &L){
    out<<L.ListaSiatkowkaPlazowa<<L.ListaPrzeciaganieLiny<<L.ListaDwaOgnie;
    return out;
}

QDataStream &operator>>(QDataStream &in, ListaDruzyn &L){
    in>>L.ListaSiatkowkaPlazowa>>L.ListaPrzeciaganieLiny>>L.ListaDwaOgnie;
    return in;
}
