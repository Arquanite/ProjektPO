#ifndef DWAOGNIE_H
#define DWAOGNIE_H

#include "pilka.h"

class DwaOgnie : public Pilka {
public:
    DwaOgnie(Druzyna Gospodarz, Druzyna Gosc, SedziaGlowny Sedzia);
    virtual bool Rozegraj();
};

#endif // DWAOGNIE_H
