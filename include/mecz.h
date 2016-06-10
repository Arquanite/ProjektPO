#ifndef MECZ_H
#define MECZ_H

#include <QString>

#include "sedziaglowny.h"

class Mecz {
protected:
    int m_PunktyGospodarza = 0;
    int m_PunktyGoscia = 0;
    QString m_Sedzia;
public:
    Mecz();
    Mecz(QString Sedzia);
    virtual ~Mecz();
    int PunktyGospodarza() const;
    int PunktyGoscia() const;
    virtual QString Rozegraj() = 0;
    QString Wynik() const;
    void WpiszWynik(int PunktyGospodarza, int PunktyGoscia);
    QString Sedzia() const;
};

#endif // MECZ_H

