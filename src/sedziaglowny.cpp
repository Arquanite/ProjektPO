#include "sedziaglowny.h"

SedziaGlowny::SedziaGlowny(QString Imie, QString Nazwisko) : Sedzia(Imie, Nazwisko){

}

SedziaGlowny::SedziaGlowny(const Osoba &O) : Sedzia(O){

}

SedziaGlowny::SedziaGlowny(){

}

QDataStream &operator<<(QDataStream &out, const SedziaGlowny &S){
    out<<S.m_Imie<<S.m_Nazwisko;
    return out;
}

QDataStream &operator>>(QDataStream &in, SedziaGlowny &S){
    in>>S.m_Imie>>S.m_Nazwisko;
    return in;
}
