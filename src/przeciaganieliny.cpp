#include "przeciaganieliny.h"

PrzeciaganieLiny::PrzeciaganieLiny(){

}

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

QDataStream &operator<<(QDataStream &out, const PrzeciaganieLiny &P){
    out<<P.m_Gosc<<P.m_Gospodarz<<P.m_PunktyGoscia<<P.m_PunktyGospodarza<<P.m_Sedzia;
    return out;
}

QDataStream &operator>>(QDataStream &in, PrzeciaganieLiny &P){
    in>>P.m_Gosc>>P.m_Gospodarz>>P.m_PunktyGoscia>>P.m_PunktyGospodarza>>P.m_Sedzia;
    return in;
}
