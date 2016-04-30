#ifndef DRUZYNA_H
#define DRUZYNA_H

#include <QList>
#include <QString>

#include"zawodnik.h"

class Druzyna {
private:
    QString m_Nazwa;
    QList<Zawodnik> m_Zawodnicy;
    int m_Punkty = 0;
public:
    Druzyna(QString Nazwa, QList<Zawodnik> Zawodnicy);
    QString Nazwa() const;
    QList<Zawodnik> Zawodnicy() const;
    int Punkty() const;
    void Wygrana();
    void Przegrana();
    bool operator == (const Druzyna &D) const;
};

#endif // DRUZYNA_H
