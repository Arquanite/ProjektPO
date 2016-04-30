#ifndef MECZINDYWIDUALNY_H
#define MECZINDYWIDUALNY_H

#include "mecz.h"
#include "zawodnik.h"

class MeczIndywidualny : public Mecz {
protected:
    Zawodnik m_Gospodarz;
    Zawodnik m_Gosc;
public:
    MeczIndywidualny(Zawodnik &Gospodarz, Zawodnik &Gosc, SedziaGlowny &Sedzia);
    Zawodnik Gospodarz() const;
    Zawodnik Gosc() const;
};

#endif // MECZINDYWIDUALNY_H
