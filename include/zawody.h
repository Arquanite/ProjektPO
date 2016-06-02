#ifndef ZAWODY_H
#define ZAWODY_H

#include "listaspotkan.h"
#include "listasedziow.h"
#include "listadruzyn.h"
#include "generator.h"

class Zawody{
protected:
    Generator m_Generator;
    ListaSpotkan m_Spotkania;
    ListaSedziow m_Sedziowie;
    ListaDruzyn m_Druzyny;
    ListaDruzyn m_Zwyciezcy;
    const int m_LiczbaOsob;
    int m_LiczbaZwyciezcow = 4;
    bool m_Zakonczone = 0;

public:
    Zawody(int IleOsobWDruzynie);
    bool ZarejestrujDruzyne(Druzyna NowaDruzyna, int Konkurencja);
    bool ZarejestrujSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy = false);

    bool UsunDruzyne(QString DruzynaDoUsuniecia);
    bool UsunSedziego(QString SedziaDoUsuniecia);

    const ListaSpotkan* Spotkania() const;
    const ListaSedziow* Sedziowie() const;
    const ListaDruzyn* Druzyny() const;
    const ListaDruzyn* Zwyciezcy() const;

    void ZaplanujSpotkania();
    void RozegrajMecze();
    void GenerujDruzyny(int Ilosc);
    void GenerujSedziow(int Ilosc);
    int  LiczbaOsob() const;
};

#endif // ZAWODY_H
