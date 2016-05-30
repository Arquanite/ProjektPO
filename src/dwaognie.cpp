#include "dwaognie.h"

DwaOgnie::DwaOgnie(QString Gospodarz, QString Gosc, QString Sedzia, int LiczbaGraczy) : Pilka(Gospodarz, Gosc, Sedzia), m_LiczbaGraczy(LiczbaGraczy){

}

QString DwaOgnie::Rozegraj(){
    while (m_PunktyGospodarza < m_LiczbaGraczy && m_PunktyGoscia < m_LiczbaGraczy){
        qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    }

    if(m_PunktyGospodarza > m_PunktyGoscia){
        return m_Gospodarz;
    }
    else {
        return m_Gosc;
    }
}
