#ifndef ZAWODY_H
#define ZAWODY_H

#include <QDataStream>

#include "listaspotkan.h"
#include "listasedziow.h"
#include "listadruzyn.h"
#include "generator.h"

enum {
    Rejestracja = 0,
    RozgrywkiPodstawowe = 1,
    //DogrywkiPodstawowe = 2,
    Polfinal = 3,
    //DogrywkiPolfinalowe = 4,
    Final = 5
};

class Zawody{
protected:
    int m_Etap = Rejestracja;
    Generator m_Generator;
    ListaSpotkan m_Spotkania;
    ListaSedziow m_Sedziowie;
    ListaDruzyn m_Druzyny;

    ListaDruzyn m_Zwyciezcy;

    int m_LiczbaMeczy = 0;
    int m_RozegraneMecze = 0;
    int m_LiczbaOsob;
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
    void RozegrajMecz(Mecz *M);
    bool GenerujDruzyny(int Ilosc, int Konkurencja);
    bool GenerujSedziow(int Ilosc, int Konkurencja, bool Pomocniczy = false);
    int  LiczbaOsob() const;
    int  Etap() const;
    QString EtapToString() const;

    friend QDataStream &operator<<(QDataStream &out, const Zawody &Z);
    friend QDataStream &operator>>(QDataStream &in, Zawody &Z);
};


#endif // ZAWODY_H
