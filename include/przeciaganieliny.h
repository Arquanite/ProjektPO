#ifndef PRZECIAGANIELINY_H
#define PRZECIAGANIELINY_H

#include "meczdruzynowy.h"

class PrzeciaganieLiny : public MeczDruzynowy {
public:
    PrzeciaganieLiny(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
    virtual bool Rozegraj();
};

#endif // PRZECIAGANIELINY_H
