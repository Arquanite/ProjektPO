#ifndef DWAOGNIE_H
#define DWAOGNIE_H

#include "pilka.h"

class DwaOgnie : public Pilka {
public:
    DwaOgnie(QString Gospodarz, QString Gosc, QString Sedzia);
    virtual QString Rozegraj() override;
};

#endif // DWAOGNIE_H
