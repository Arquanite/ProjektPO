#ifndef PRZECIAGANIELINY_H
#define PRZECIAGANIELINY_H

#include <QDataStream>
#include "meczdruzynowy.h"

class PrzeciaganieLiny : public MeczDruzynowy {
public:
    PrzeciaganieLiny();
    PrzeciaganieLiny(QString Gospodarz, QString Gosc, QString Sedzia);
    virtual QString Rozegraj() override;

    friend QDataStream &operator<<(QDataStream &out, const PrzeciaganieLiny &P);
    friend QDataStream &operator>>(QDataStream &in, PrzeciaganieLiny &P);
};

#endif // PRZECIAGANIELINY_H
