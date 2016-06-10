#ifndef PILKA_H
#define PILKA_H

#include "meczdruzynowy.h"

class Pilka : public MeczDruzynowy {
public:
    Pilka();
    Pilka(QString Gospodarz, QString Gosc, QString Sedzia);
};

#endif // PILKA_H
