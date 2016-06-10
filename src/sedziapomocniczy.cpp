#include "sedziapomocniczy.h"

SedziaPomocniczy::SedziaPomocniczy(QString Imie, QString Nazwisko) : Sedzia(Imie, Nazwisko){

}

SedziaPomocniczy::SedziaPomocniczy(const Osoba &O) : Sedzia(O){

}

SedziaPomocniczy::SedziaPomocniczy(){

}

QDataStream &operator<<(QDataStream &out, const SedziaPomocniczy &S){
    out<<S.m_Imie<<S.m_Nazwisko;
    return out;
}

QDataStream &operator>>(QDataStream &in, SedziaPomocniczy &S){
    in>>S.m_Imie>>S.m_Nazwisko;
    return in;
}
