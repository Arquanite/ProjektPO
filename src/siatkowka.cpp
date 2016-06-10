#include "siatkowka.h"

Siatkowka::Siatkowka(){

}

Siatkowka::Siatkowka(QString Gospodarz, QString Gosc, QString Sedzia, QString SedziaPomocniczy1, QString SedziaPomocniczy2)
    : Pilka(Gospodarz, Gosc, Sedzia), m_SedziaPomocniczy1(SedziaPomocniczy1), m_SedziaPomocniczy2(SedziaPomocniczy2) {

}

QString Siatkowka::SedziaPomocniczy1() const {
    return m_SedziaPomocniczy1;
}

QString Siatkowka::SedziaPomocniczy2() const {
    return m_SedziaPomocniczy2;
}

QString Siatkowka::Rozegraj(){
    if(qrand()%100 < 20){
        int Punkty = qrand()%24;
        if(qrand()%2){
            m_PunktyGospodarza = 25;
            m_PunktyGoscia = Punkty;
        }
        else {
            m_PunktyGospodarza = Punkty;
            m_PunktyGoscia = 25;
        }
    }
    else {
        int Punkty = qrand()%20 + 25;
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
