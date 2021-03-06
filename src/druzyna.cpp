#include "druzyna.h"

Druzyna::Druzyna(QString Nazwa, QList<Zawodnik> Zawodnicy) : m_Nazwa(Nazwa), m_Zawodnicy(Zawodnicy){

}

Druzyna::Druzyna(const Druzyna &D) : m_Nazwa(D.Nazwa()), m_Zawodnicy(D.Zawodnicy()), m_Punkty(D.Punkty()){

}

Druzyna::Druzyna() : m_Nazwa(">>BRAK NAZWY<<"){

}

QString Druzyna::Nazwa() const {
    return m_Nazwa;
}

QList<Zawodnik> Druzyna::Zawodnicy() const {
    return m_Zawodnicy;
}


int Druzyna::Punkty() const{
    return m_Punkty;
}

void Druzyna::Wygrana(){
    m_Punkty += 1;
}

void Druzyna::Przegrana(){
    m_Punkty += 0;
}

bool Druzyna::operator == (const Druzyna &D) const{
    return ( m_Nazwa == D.m_Nazwa && m_Zawodnicy == D.m_Zawodnicy );
}

QDataStream &operator<<(QDataStream &out, const Druzyna &D){
    out<<D.m_Nazwa<<D.m_Punkty<<D.m_Zawodnicy;
    return out;
}

QDataStream &operator>>(QDataStream &in, Druzyna &D){
    in>>D.m_Nazwa>>D.m_Punkty>>D.m_Zawodnicy;
    return in;
}
