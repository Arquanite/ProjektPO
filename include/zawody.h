#ifndef ZAWODY_H
#define ZAWODY_H

#include <QDataStream>

#include "listaspotkan.h"
#include "listasedziow.h"
#include "listadruzyn.h"
#include "generator.h"

/**
 * @brief Umożliwia łatwe odczytanie aktualnego etapu rozgrywek.
 */
enum EtapRozgrywek{
    Rejestracja = 0,
    RozgrywkiPodstawowe = 1,
    Polfinal = 2,
    Final = 3
};

/**
 * @brief Klasa reprezentująca zawody.
 *
 * Zajmuje się przedewszystkim rejestracją drużyn i sędziów. Dba o spójność
 * informacji. Planuje spotkania, umożliwia dodawanie danych losowych z generatora.
 */
class Zawody{
protected:
    int m_Etap = Rejestracja; ///< Przechowuje aktualny etap rozgrywek.
    Generator m_Generator; ///< Obiekt generatora nazw.
    ListaSpotkan m_Spotkania; ///< Przechowuje informacje o spotkaniach.
    ListaSedziow m_Sedziowie; ///< Przechowuje informacje o sędziach.
    ListaDruzyn m_Druzyny; ///< Przechowuje informacje o drużynach.

    ListaDruzyn m_Zwyciezcy; ///< Przechowuje informacje o zwycięzcach.

    int m_LiczbaMeczy = 0;
    int m_RozegraneMecze = 0;
    int m_LiczbaOsob;
    int m_LiczbaZwyciezcow = 4;
    bool m_Zakonczone = 0;

public:
    Zawody(int IleOsobWDruzynie); ///< Konstruktor, wymaga podania ile osób będzie w każdej z drużyn.

    /**
     * @brief Dodaje nową drużynę do zawodów.
     * @param NowaDruzyna Drużyna, którą chcemy dodać.
     * @param Konkurencja Konkurencja, w której będzie uczestniczyć.
     * @return true jeżeli dodawane się powiodło, jeżeli drużyna o tej samej nazwie już istnieje - false.
     */
    bool ZarejestrujDruzyne(Druzyna NowaDruzyna, int Konkurencja);

    /**
     * @brief Dodaje nowego sędziego do zawodów.
     * @param NowySedzia NowySedzia, którego chcemy dodać.
     * @param Konkurencja Konkurencja, w której będzie sędziować.
     * @param Pomocniczy Określa typ sędziego, true - pomocniczy, false - główny.
     * @return true jeżeli dodawane się powiodło, jeżeli sędzia o tej samej nazwie już istnieje - false.
     */
    bool ZarejestrujSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy = false);

    /**
     * @brief Usuwa z zawodów drużynę o podanej nazwie.
     * @param DruzynaDoUsuniecia Nazwa drużyny, którą chcemy usunąć.
     * @return true jeżeli usuwanie się powiodło, jeżeli taka drużyna nie istnieje - false.
     */
    bool UsunDruzyne(QString DruzynaDoUsuniecia);

    /**
     * @brief Usuwa z zawodów sędziego o podanej nazwie.
     * @param SedziaDoUsuniecia Nazwa sędziego, którego chcemy usunąć.
     * @return true jeżeli usuwanie się powiodło, jeżeli taki sędzia nie istnieje - false.
     */
    bool UsunSedziego(QString SedziaDoUsuniecia);

    const ListaSpotkan* Spotkania() const; ///< Zwraca wskaźnik do danych o spotkaniach.
    const ListaSedziow* Sedziowie() const; ///< Zwraca wskaźnik do danych o sędziach.
    const ListaDruzyn* Druzyny() const; ///< Zwraca wskaźnik do danych o drużynach.
    const ListaDruzyn* Zwyciezcy() const; ///< Zwraca wskaźnik do danych o zwycięzcach.

    void ZaplanujSpotkania(); ///< Planuje spotkania na zasadzie każdy z każdym.
    void RozegrajMecze(); ///< Wywołuje we wszystkich meczach metodę Rozegraj().
    void RozegrajMecz(Mecz *M); ///< Rozgrywa konkretny mecz.
    bool GenerujDruzyny(int Ilosc, int Konkurencja); ///< Generuje podaną ilość drużyn i dodaje je do danej konkurencji.
    bool GenerujSedziow(int Ilosc, int Konkurencja, bool Pomocniczy = false); ///< Generuje podaną ilość sędziów i dodaje ich do danej konkurencji.
    int  LiczbaOsob() const; ///< Zwraca liczbę osób w jednej drużynie.
    int  Etap() const; ///< Zwraca identyfikator aktualnego etapu rozgrywek.
    QString EtapToString() const; ///< Zwraca aktualny etap w postaci czytelnej dla człowieka.

    friend QDataStream &operator<<(QDataStream &out, const Zawody &Z); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, Zawody &Z); ///< Umożliwia deserializację.

};


#endif // ZAWODY_H
