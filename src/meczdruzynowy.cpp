#include "meczdruzynowy.h"

MeczDruzynowy::MeczDruzynowy(Druzyna &Gospodarz, Druzyna &Gosc, SedziaGlowny Sedzia) : Mecz(Sedzia), m_Gospodarz(Gospodarz), m_Gosc(Gosc){

}

Druzyna MeczDruzynowy::Gospodarz() const {
    return m_Gospodarz;
}

Druzyna MeczDruzynowy::Gosc() const {
    return m_Gosc;
}
