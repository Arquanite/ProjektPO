#include "dwaognie.h"

DwaOgnie::DwaOgnie(QString Gospodarz, QString Gosc, QString Sedzia) : Pilka(Gospodarz, Gosc, Sedzia){

}

QString DwaOgnie::Rozegraj(){
    /*! FIXME PLZ int LiczbaGraczy = m_Gospodarz.Zawodnicy().size();

    while (m_PunktyGospodarza < LiczbaGraczy && m_PunktyGoscia < LiczbaGraczy){
        qrand()%2 ? m_PunktyGospodarza++ : m_PunktyGoscia++;
    }*/

    if(m_PunktyGospodarza > m_PunktyGoscia){
        return m_Gospodarz;
    }
    else {
        return m_Gosc;
    }
}
