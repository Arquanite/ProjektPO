#include "meczindywidualny.h"

MeczIndywidualny::MeczIndywidualny(QString Gospodarz, QString Gosc, QString Sedzia) : Mecz(Sedzia), m_Gospodarz(Gospodarz), m_Gosc(Gosc){

}

QString MeczIndywidualny::Gospodarz() const {
    return m_Gospodarz;
}

QString MeczIndywidualny::Gosc() const {
    return m_Gosc;
}
