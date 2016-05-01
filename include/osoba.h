#ifndef OSOBA_H
#define OSOBA_H

#include <QString>

class Osoba {
protected:
    QString m_Imie;
    QString m_Nazwisko;
public:
    Osoba(QString Imie, QString Nazwisko);
    virtual ~Osoba();
    QString Imie() const;
    void ZmienImie(const QString &Imie);
    QString Nazwisko() const;
    void ZmienNazwisko(const QString &Nazwisko);
    bool operator == (const Osoba &O) const;
};

#endif // OSOBA_H
