#ifndef LISTADRUZYN_H
#define LISTADRUZYN_H

#include <QDataStream>
#include <QMap>

#include "druzyna.h"

/**
 * @brief Przechowuje dane drużyn.
 *
 * Jest to swego rodzaju kontener zawierający mapy z drużynami dla każdej z dyscyplin.
 * W mapach kluczem jest nazwa drużyny.
 */
class ListaDruzyn{
public:
    QMap<QString,Druzyna> ListaSiatkowkaPlazowa; ///< Dane drużyn uczestniczących w siatkówce plażowej.
    QMap<QString,Druzyna> ListaPrzeciaganieLiny; ///< Dane drużyn uczestniczących w przeciąganiu liny.
    QMap<QString,Druzyna> ListaDwaOgnie; ///< Dane drużyn uczestniczących w dwóch ogniach.

    friend QDataStream &operator<<(QDataStream &out, const ListaDruzyn &L); ///< Umożliwa serializację.
    friend QDataStream &operator>>(QDataStream &in, ListaDruzyn &L); ///< Umożliwia deserializację.
};

#endif // LISTADRUZYN_H
