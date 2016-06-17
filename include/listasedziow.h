#ifndef LISTASEDZIOW_H
#define LISTASEDZIOW_H

#include <QMap>
#include <QDataStream>

#include "sedziaglowny.h"
#include "sedziapomocniczy.h"

/**
 * @brief Przechowuje dane sędziów.
 *
 * Jest to swego rodzaju kontener zawierający mapy z sędziami dla każdej z dyscyplin.
 * W mapach kluczem jest nazwisko i imie sędziego (ze spacją).
 */
class ListaSedziow{
public:
    QMap<QString,SedziaGlowny> ListaSiatkowkaPlazowaGlowny; ///< Dane sędziów głównych sędziujących w siatkówce plażowej.
    QMap<QString,SedziaPomocniczy> ListaSiatkowkaPlazowaPomocniczy; ///< Dane sędziów pomocniczych sędziujących w siatkówce plażowej.
    QMap<QString,SedziaGlowny> ListaPrzeciaganieLinyGlowny; ///< Dane sędziów głównych sędziujących w przeciąganiu liny.
    QMap<QString,SedziaGlowny> ListaDwaOgnieGlowny; ///< Dane sędziów głównych sędziujących w dwóch ogniach.

    friend QDataStream &operator<<(QDataStream &out, const ListaSedziow &L); ///< Umożliwia serializację.
    friend QDataStream &operator>>(QDataStream &in, ListaSedziow &L); ///< Umożliwia deserializację.
};

#endif // LISTASEDZIOW_H
