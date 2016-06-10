#include "zawodnik.h"

Zawodnik::Zawodnik(QString Imie, QString Nazwisko) : Osoba(Imie, Nazwisko){

}

Zawodnik::Zawodnik(const Osoba &O) : Osoba(O){

}

Zawodnik::Zawodnik(){

}

QDataStream &operator<<(QDataStream &out, const Zawodnik &Z){
    out<<Z.m_Imie<<Z.m_Nazwisko;
    return out;
}

QDataStream &operator>>(QDataStream &in, Zawodnik &Z){
    in>>Z.m_Imie>>Z.m_Nazwisko;
    return in;
}
