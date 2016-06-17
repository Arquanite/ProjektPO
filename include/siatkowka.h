#ifndef SIATKOWKA_H
#define SIATKOWKA_H

#include "pilka.h"
#include "sedziapomocniczy.h"

/**
 * @brief Klasa reprezentująca mecz siatkówki.
 *
 * W siatkówce oprócz drużyn i sędziego głównego znajduje się także dwóch sędziów pomocniczych.
 *
 * @see SiatkowkaPlazowa
 */
class Siatkowka : public Pilka {
protected:
    QString m_SedziaPomocniczy1;
    QString m_SedziaPomocniczy2;
public:
    Siatkowka(); ///< Konstruktor domyślny, nie należy go używać.
    Siatkowka(QString Gospodarz, QString Gosc, QString Sedzia, QString SedziaPomocniczy1, QString SedziaPomocniczy2); ///< Konstruktor.
    QString SedziaPomocniczy1() const; ///< Zwraca nazwę pierwszego sędziego pomocniczego.
    QString SedziaPomocniczy2() const; ///< Zwraca nazwę drugiego sędziego pomocniczego.
    virtual QString Rozegraj() override; ///< Powoduje uzyskanie wyniku charakterystycznego dla tej dyscypliny, zwraca nazwę zwycięzcy.
};

#endif // SIATKOWKA_H
