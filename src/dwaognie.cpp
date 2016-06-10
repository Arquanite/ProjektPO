#include "dwaognie.h"

DwaOgnie::DwaOgnie(){

}

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

QDataStream &operator<<(QDataStream &out, const DwaOgnie &D){
    out<<D.m_Gosc<<D.m_Gospodarz<<D.m_LiczbaGraczy<<D.m_PunktyGoscia<<D.m_PunktyGospodarza<<D.m_Sedzia;
    return out;
}

QDataStream &operator>>(QDataStream &in, DwaOgnie &D){
    in>>D.m_Gosc>>D.m_Gospodarz>>D.m_LiczbaGraczy>>D.m_PunktyGoscia>>D.m_PunktyGospodarza>>D.m_Sedzia;
    return in;
}
