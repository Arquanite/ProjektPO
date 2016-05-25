#include "przeciaganieliny.h"

PrzeciaganieLiny::PrzeciaganieLiny(QString Gospodarz, QString Gosc, QString Sedzia) : MeczDruzynowy(Gospodarz, Gosc, Sedzia){

}

QString PrzeciaganieLiny::Rozegraj(){
    //Rozgrywka w 5 rundach
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;

    if(m_PunktyGospodarza > m_PunktyGoscia){
        return m_Gospodarz;
    }
    else {
        return m_Gosc;
    }
}
