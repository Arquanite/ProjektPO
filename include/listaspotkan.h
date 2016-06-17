#ifndef LISTASPOTKAN_H
#define LISTASPOTKAN_H

#include <QList>
#include <QDataStream>

#include "siatkowkaplazowa.h"
#include "przeciaganieliny.h"
#include "dwaognie.h"

/**
 * @brief Przechowuje dane o meczach.
 *
 * Jest to swego rodzaju kontener zawierający listy z meczami dla każdej z dyscyplin.
 */
class ListaSpotkan {
public:
    QList<SiatkowkaPlazowa> ListaSiatkowkaPlazowa; ///< Lista meczy siatkówki plażowej.
    QList<PrzeciaganieLiny> ListaPrzeciaganieLiny; ///< Lista meczy przeciągania liny.
    QList<DwaOgnie> ListaDwaOgnie; ///< Lista meczy dwóch ogni.

    friend QDataStream &operator<<(QDataStream &out, const ListaSpotkan &L); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, ListaSpotkan &L); ///< Umożliwia deserializację,
};

#endif // LISTASPOTKAN_H
