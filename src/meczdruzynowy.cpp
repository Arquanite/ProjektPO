#include "meczdruzynowy.h"

MeczDruzynowy::MeczDruzynowy(){

}

MeczDruzynowy::MeczDruzynowy(QString Gospodarz, QString Gosc, QString Sedzia) : Mecz(Sedzia), m_Gospodarz(Gospodarz), m_Gosc(Gosc){

}

QString MeczDruzynowy::Gospodarz() const {
    return m_Gospodarz;
}

QString MeczDruzynowy::Gosc() const {
    return m_Gosc;
}
