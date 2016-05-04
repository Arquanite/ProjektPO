#ifndef MECZDRUZYNOWY_H
#define MECZDRUZYNOWY_H

#include "mecz.h"
#include "druzyna.h"

class MeczDruzynowy : public Mecz {
protected:
    Druzyna m_Gospodarz;
    Druzyna m_Gosc;
public:
    MeczDruzynowy(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
    Druzyna Gospodarz() const;
    Druzyna Gosc() const;
};

#endif // MECZDRUZYNOWY_H
