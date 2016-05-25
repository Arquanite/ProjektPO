#include "meczindywidualny.h"

MeczIndywidualny::MeczIndywidualny(Zawodnik Gospodarz, Zawodnik Gosc, SedziaGlowny Sedzia) : Mecz(Sedzia), m_Gospodarz(Gospodarz), m_Gosc(Gosc){

}

Zawodnik MeczIndywidualny::Gospodarz() const {
    return m_Gospodarz;
}

Zawodnik MeczIndywidualny::Gosc() const {
    return m_Gosc;
}
