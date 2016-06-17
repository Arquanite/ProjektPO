#ifndef PILKA_H
#define PILKA_H

#include "meczdruzynowy.h"

/**
 * @brief Abstrakcyjna klasa reprezentująca mecz piłki.
 *
 */
class Pilka : public MeczDruzynowy {
public:
    Pilka(); ///< Kostruktor domyślny, nie należy go używać.
    Pilka(QString Gospodarz, QString Gosc, QString Sedzia); ///< Konstruktor.
};

#endif // PILKA_H
