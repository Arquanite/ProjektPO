#ifndef PRZECIAGANIELINY_H
#define PRZECIAGANIELINY_H

#include "meczdruzynowy.h"

class PrzeciaganieLiny : public MeczDruzynowy {
public:
    PrzeciaganieLiny(QString Gospodarz, QString Gosc, QString Sedzia);
    virtual QString Rozegraj() override;
};

#endif // PRZECIAGANIELINY_H
