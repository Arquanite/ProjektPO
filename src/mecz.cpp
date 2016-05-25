#include "mecz.h"

Mecz::~Mecz(){

}

Mecz::Mecz(SedziaGlowny Sedzia) : m_Sedzia(Sedzia){

}

int Mecz::PunktyGoscia() const {
    return m_PunktyGoscia;
}

SedziaGlowny Mecz::Sedzia() const
{
    return m_Sedzia;
}

int Mecz::PunktyGospodarza() const {
    return m_PunktyGospodarza;
}

QString Mecz::Wynik() const {
    return QString::number(m_PunktyGospodarza) + ":" + QString::number(m_PunktyGoscia);
}

void Mecz::WpiszWynik(int PunktyGospodarza, int PunktyGoscia){
    m_PunktyGospodarza = PunktyGospodarza;
    m_PunktyGoscia =  PunktyGoscia;
}
