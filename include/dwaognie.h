#ifndef DWAOGNIE_H
#define DWAOGNIE_H

#include <QDataStream>
#include "pilka.h"

/**
 * @brief Klasa reprezentująca mecz w dwa ognie.
 *
 * @see SiatkowkaPlazowa
 * @see PrzeciaganieLiny
 */
class DwaOgnie : public Pilka {
protected:
    int m_LiczbaGraczy;
public:
    DwaOgnie(); ///< Konstruktor domyślny, nie należy go używać.
    /**
     * @brief Konstruktor.
     * @param Gospodarz Nazwa drużyny gospodarza.
     * @param Gosc Nazwa drużyny gościa.
     * @param Sedzia Nazwa sędziego.
     * @param LiczbaGraczy Liczba graczy w drużynie.
     */
    DwaOgnie(QString Gospodarz, QString Gosc, QString Sedzia, int LiczbaGraczy);
    virtual QString Rozegraj() override; ///< Symuluje rozgrywkę, ustawia wynik.

    friend QDataStream &operator<<(QDataStream &out, const DwaOgnie &D); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, DwaOgnie &D); ///< Umożliwia deserializację.
};

#endif // DWAOGNIE_H
