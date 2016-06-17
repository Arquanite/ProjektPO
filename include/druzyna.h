#ifndef DRUZYNA_H
#define DRUZYNA_H

#include <QList>
#include <QString>
#include <QDataStream>

#include"zawodnik.h"

/**
 * @brief Klasa reprezentującą drużynę, zawiera zawodników.
 *
 * Zawiera unikalną nazwę oraz listę zawodników.
 *
 * @see Zawodnik
 */
class Druzyna {
private:
    QString m_Nazwa;
    QList<Zawodnik> m_Zawodnicy;
    int m_Punkty = 0;
public:
    /**
     * @brief Konstruktor domyślny, nie należy go używać do tworzenia drużyn,
     * gdyż może to prowadzić do powstania drużyny bez nazwy lub zawodników.
     */
    Druzyna();

    /**
     * @brief Konstruktor, tworzy nową drużynę, przydziela jej nazwę oraz zawodników.
     */
    Druzyna(QString Nazwa, QList<Zawodnik> Zawodnicy);
    Druzyna(const Druzyna &D); ///< Konstruktor kopiujący.
    QString Nazwa() const; ///< Zwraca nazwę drużyny.
    QList<Zawodnik> Zawodnicy() const; ///< Zwraca listę zawodników.
    int Punkty() const; ///< Zwraca punkty zdobyte przez drużynę.
    void Wygrana(); ///< Dodaje punkt dla drużyny.
    void Przegrana(); ///< Nie robi nic.

    bool operator == (const Druzyna &D) const; ///< Zwraca prawdę kiedy obie drużyny mają tę samą nazwę i zawodników (mogą się różnić punktami).

    friend QDataStream &operator<<(QDataStream &out, const Druzyna &D); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, Druzyna &D); ///< Umożliwia deserializację.
};

#endif // DRUZYNA_H
