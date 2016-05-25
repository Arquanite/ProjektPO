#ifndef MECZ_H
#define MECZ_H

#include <QString>

#include "sedziaglowny.h"

class Mecz {
protected:
    int m_PunktyGospodarza = 0;
    int m_PunktyGoscia = 0;
    SedziaGlowny m_Sedzia;
public:
    virtual ~Mecz();
    Mecz(SedziaGlowny Sedzia);
    int PunktyGospodarza() const;
    int PunktyGoscia() const;
    virtual bool Rozegraj() = 0;
    QString Wynik() const;
    void WpiszWynik(int PunktyGospodarza, int PunktyGoscia);
    SedziaGlowny Sedzia() const;
};

#endif // MECZ_H

