#include "przeciaganieliny.h"

PrzeciaganieLiny::PrzeciaganieLiny(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia) : MeczDruzynowy(Gospodarz, Gosc, Sedzia){

}

bool PrzeciaganieLiny::Rozegraj(){
    //Rozgrywka w 5 rundach
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;

    if(m_PunktyGospodarza > m_PunktyGoscia){
        m_Gospodarz.Wygrana();
        return true;
    }
    else {
        m_Gosc.Wygrana();
        return false;
    }
}
