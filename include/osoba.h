#ifndef OSOBA_H
#define OSOBA_H

#include <QString>

/**
 * @brief Klasa reprezentująca człowieka, zawiera imię i nazwisko.
 *
 * Jest bazą dla innych, wyspecjalizowanych typów osób uczestniczących w zawodach.
 *
 * @see Zawodnik
 * @see Sedzia
 *
 */
class Osoba {
protected:
    QString m_Imie; ///< Przechowuje imię osoby.
    QString m_Nazwisko; ///< Przechowuje nazwisko osoby.
public:
    Osoba(QString Imie, QString Nazwisko); ///< Konstruktor, tworzy nową osobę oraz nadaje jej imię i nazwisko.
    Osoba(const Osoba &O); ///< Konstruktor kopiujący.

    /**
     * @brief Konstruktor domyślny, nie należy go używać do tworzenia osób gdyż może
     * to spowodować powstanie osób bez imienia i nazwiska.
     */
    Osoba();    
    virtual ~Osoba(); ///< Destruktor.

    QString Imie() const; ///< Zwraca imię osoby.
    void ZmienImie(const QString &Imie); /// Zmienia imie osoby.

    QString Nazwisko() const; ///< Zwraca Nazwisko osoby.
    void ZmienNazwisko(const QString &Nazwisko); ///< Zmienia nazwisko osoby.

    bool operator == (const Osoba &O) const; ///< Zwraca prawdę jeżeli imiona i nazwiska dwóch osób są takie same.
};

#endif // OSOBA_H
