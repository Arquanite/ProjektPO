#ifndef PRZECIAGANIELINY_H
#define PRZECIAGANIELINY_H

#include <QDataStream>
#include "meczdruzynowy.h"

/**
 * @brief Klasa reprezentująca mecz przeciągania liny.
 *
 * @see SiatkowkaPlazowa
 * @see DwaOgnie
 */
class PrzeciaganieLiny : public MeczDruzynowy {
public:
    PrzeciaganieLiny(); ///< Konstruktor domyślny, nie należy go używać.
    PrzeciaganieLiny(QString Gospodarz, QString Gosc, QString Sedzia); ///< Konstruktor.
    virtual QString Rozegraj() override; ///< Powoduje uzyskanie wyniku charakterystycznego dla tej dyscypliny, zwraca nazwę zwycięzcy.

    friend QDataStream &operator<<(QDataStream &out, const PrzeciaganieLiny &P); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, PrzeciaganieLiny &P); ///< Umożliwia deserializację.
};

#endif // PRZECIAGANIELINY_H
