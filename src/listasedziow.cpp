#include "listasedziow.h"

QDataStream &operator<<(QDataStream &out, const ListaSedziow &L){
    out<<L.ListaSiatkowkaPlazowaGlowny<<L.ListaSiatkowkaPlazowaPomocniczy<<L.ListaPrzeciaganieLinyGlowny<<L.ListaDwaOgnieGlowny;
    return out;
}

QDataStream &operator>>(QDataStream &in, ListaSedziow &L){
    in>>L.ListaSiatkowkaPlazowaGlowny>>L.ListaSiatkowkaPlazowaPomocniczy>>L.ListaPrzeciaganieLinyGlowny>>L.ListaDwaOgnieGlowny;
    return in;
}
