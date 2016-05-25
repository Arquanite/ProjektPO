#include "siatkowkaplazowa.h"

SiatkowkaPlazowa::SiatkowkaPlazowa(QString Gospodarz, QString Gosc, QString Sedzia, QString SedziaPomocniczy1, QString SedziaPomocniczy2)
    : Siatkowka(Gospodarz, Gosc, Sedzia, SedziaPomocniczy1, SedziaPomocniczy2){

}

QString SiatkowkaPlazowa::Rozegraj(){
    if(qrand()%100 < 20){
        int Punkty = qrand()%20;
        if(qrand()%2){
            m_PunktyGospodarza = 21;
            m_PunktyGoscia = Punkty;
        }
        else {
            m_PunktyGospodarza = Punkty;
            m_PunktyGoscia = 21;
        }
    }
    else {
        int Punkty = qrand()%20 + 21;
        if(qrand()%2){
            m_PunktyGospodarza = Punkty;
            m_PunktyGoscia = Punkty + 2;
        }
        else {
            m_PunktyGospodarza = Punkty + 2;
            m_PunktyGoscia = Punkty;
        }
    }

    if(m_PunktyGospodarza > m_PunktyGoscia){
        return m_Gospodarz;
    }
    else {
        return m_Gosc;
    }
}
