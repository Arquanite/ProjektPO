#ifndef ZAWODY_H
#define ZAWODY_H

#include "listaspotkan.h"
#include "listasedziow.h"
#include "listadruzyn.h"

class Zawody{
protected:
    ListaSpotkan m_Spotkania;
    ListaSedziow m_Sedziowie;
    ListaDruzyn m_Druzyny;
    ListaDruzyn m_Zwyciezcy;
    int m_LiczbaZwyciezcow = 4;
    bool m_Zakonczone = 0;
public:
    bool ZarejestrujDruzyne(Druzyna NowaDruzyna, int Konkurencja);
    bool ZarejestrujSedziegoGlownego(SedziaGlowny NowySedzia, int Konkurencja);

    bool UsunDruzyne(Druzyna DruzynaDoUsuniecia);
    bool UsunSedziego(Sedzia SedziaDoUsuniecia);

    ListaSpotkan Spotkania() const;
    ListaSedziow Sedziowie() const;
    ListaDruzyn Druzyny() const;
    ListaDruzyn Zwyciezcy() const;

    void ZaplanujSpotkania();
    void RozegrajMecze();
};

#endif // ZAWODY_H
