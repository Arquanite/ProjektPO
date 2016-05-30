#ifndef DWAOGNIE_H
#define DWAOGNIE_H

#include "pilka.h"

class DwaOgnie : public Pilka {
protected:
    int m_LiczbaGraczy;
public:
    DwaOgnie(QString Gospodarz, QString Gosc, QString Sedzia, int LiczbaGraczy);
    virtual QString Rozegraj() override;
};

#endif // DWAOGNIE_H
