#include "osoba.h"

Osoba::Osoba(QString Imie, QString Nazwisko) : m_Imie(Imie), m_Nazwisko(Nazwisko) {

}

Osoba::Osoba(const Osoba &O) : m_Imie(O.m_Imie), m_Nazwisko(O.m_Nazwisko){

}

Osoba::Osoba(){

}

Osoba::~Osoba(){

}

QString Osoba::Imie() const {
    return m_Imie;
}

void Osoba::ZmienImie(const QString &Imie){
    m_Imie = Imie;
}

QString Osoba::Nazwisko() const {
    return m_Nazwisko;
}

void Osoba::ZmienNazwisko(const QString &Nazwisko){
    m_Nazwisko = Nazwisko;
}

bool Osoba::operator == (const Osoba &O) const{
    return (m_Imie == O.m_Imie && m_Nazwisko == O.m_Nazwisko);
}
