#ifndef MECZDRUZYNOWY_H
#define MECZDRUZYNOWY_H

#include "mecz.h"
#include "druzyna.h"

/**
 * @brief Abstrakcyjna klasa reprezentująca mecz, w którym przeciwko sobie grają dwie drużyny.
 *
 * @see MeczIndywidualny
 */
class MeczDruzynowy : public Mecz {
protected:
    QString m_Gospodarz;
    QString m_Gosc;
public:
    MeczDruzynowy(); ///< Kostruktor domyślny, nie należy go używać.
    MeczDruzynowy(QString Gospodarz, QString Gosc, QString Sedzia); ///< Kostruktor.
    QString Gospodarz() const; ///< Zwraca nazwę gospodarza.
    QString Gosc() const; ///< Zwraca nazwę gościa.
};

#endif // MECZDRUZYNOWY_H
