#ifndef SIATKOWKAPLAZOWA_H
#define SIATKOWKAPLAZOWA_H

#include <QDataStream>
#include "siatkowka.h"

/**
 * @brief Klasa reprezentująca mecz siatkówki plażowej.
 *
 * Podobnie jak w siatkówce oprócz drużyn i sędziego głównego znajduje się także dwóch sędziów pomocniczych.
 *
 * @see PrzeciaganieLiny
 * @see DwaOgnie
 */
class SiatkowkaPlazowa : public Siatkowka {
public:
    SiatkowkaPlazowa(); ///< Konstruktor domyślny, nie należy go używać.
    SiatkowkaPlazowa(QString Gospodarz, QString Gosc, QString Sedzia, QString SedziaPomocniczy1, QString SedziaPomocniczy2); ///< Konstruktor.
    virtual QString Rozegraj() override;  ///< Powoduje uzyskanie wyniku charakterystycznego dla tej dyscypliny, zwraca nazwę zwycięzcy.

    friend QDataStream &operator<<(QDataStream &out, const SiatkowkaPlazowa &P); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, SiatkowkaPlazowa &P); ///< Umożliwia deserializację.
};

#endif // SIATKOWKAPLAZOWA_H
