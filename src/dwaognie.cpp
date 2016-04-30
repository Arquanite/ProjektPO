#include "dwaognie.h"

DwaOgnie::DwaOgnie(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia) : Pilka(Gospodarz, Gosc, Sedzia){

}

bool DwaOgnie::Rozegraj(){
    int LiczbaGraczy = m_Gospodarz.Zawodnicy().size();

    while (m_PunktyGospodarza < LiczbaGraczy && m_PunktyGoscia < LiczbaGraczy){
        qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    }

    if(m_PunktyGospodarza > m_PunktyGoscia){
        m_Gospodarz.Wygrana();
        return true;
    }
    else {
        m_Gosc.Wygrana();
        return false;
    }
}
