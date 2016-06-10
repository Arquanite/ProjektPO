#ifndef DWAOGNIE_H
#define DWAOGNIE_H

#include <QDataStream>
#include "pilka.h"

class DwaOgnie : public Pilka {
protected:
    int m_LiczbaGraczy;
public:
    DwaOgnie();
    DwaOgnie(QString Gospodarz, QString Gosc, QString Sedzia, int LiczbaGraczy);
    virtual QString Rozegraj() override;

    friend QDataStream &operator<<(QDataStream &out, const DwaOgnie &D);
    friend QDataStream &operator>>(QDataStream &in, DwaOgnie &D);
};

#endif // DWAOGNIE_H
