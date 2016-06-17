#ifndef MECZINDYWIDUALNY_H
#define MECZINDYWIDUALNY_H

#include "mecz.h"
#include "zawodnik.h"

/**
 * @brief Abstrakcyjna klasa reprezentująca mecz, w którym przeciwko sobie grają dwaj zawodnicy.
 *
 * @see MeczDruzynowy
 */
class MeczIndywidualny : public Mecz {
protected:
    QString m_Gospodarz;
    QString m_Gosc;
public:
    MeczIndywidualny(QString Gospodarz, QString Gosc, QString Sedzia); ///< Kostruktor.
    QString Gospodarz() const; ///< Zwraca nazwę gospodarza.
    QString Gosc() const; ///< Zwraca nazwę gościa.
};

#endif // MECZINDYWIDUALNY_H
