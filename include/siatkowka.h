#ifndef SIATKOWKA_H
#define SIATKOWKA_H

#include "pilka.h"
#include "sedziapomocniczy.h"

class Siatkowka : public Pilka {
private:
    QString m_SedziaPomocniczy1;
    QString m_SedziaPomocniczy2;
public:
    Siatkowka(QString Gospodarz, QString Gosc, QString Sedzia, QString SedziaPomocniczy1, QString SedziaPomocniczy2);
    QString SedziaPomocniczy1() const;
    QString SedziaPomocniczy2() const;
    virtual QString Rozegraj() override;
};

#endif // SIATKOWKA_H
