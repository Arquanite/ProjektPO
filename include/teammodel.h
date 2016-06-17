#ifndef TEAMMODEL_H
#define TEAMMODEL_H

#include <QAbstractTableModel>
#include "listadruzyn.h"

/**
 * @brief Model przetwarzający dane drużyn.
 *
 * Tworzy tabelę, w której w każym wierszu znajdują się dane o innym meczu.
 * Tworzy o 3 więcej kolumn niż jest zawodników w drużynie, znajdują się w nich kolejno:
 * nazwa drużyny, zdobyte przez nią punkty, konkurencja w której gra, a w następnych
 * imiona i nazwiska zawodników.
 *
 * @see MatchModel
 * @see UmpireModel
 */
class TeamModel : public QAbstractTableModel {
    Q_OBJECT
private:
    const ListaDruzyn *m_Druzyny;
    const int m_LiczbaZawodnikow;
public:
    /**
     * @brief Konstruktor
     * @param Spotkania Lista wszystkich drużyn w zawodach.
     * @param LiczbaOsobWDruzynie Określa liczbę osób w każdej z drużyn.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit TeamModel(const ListaDruzyn *Druzyny, int LiczbaOsobWDruzynie, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override; ///< Zwraca ilość wierszy.
    int columnCount(const QModelIndex &parent = QModelIndex()) const override; ///< Zwraca ilość kolumn.

    void AddRow(); ///< Dodaje nowy wiersz.
    void DeleteRow(int index); ///< Usuwa wiersz o podanym indeksie.

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; ///< Zwraca dane znajdujące się na polu o konkretnym indeksie.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override; ///< Zwraca dane określonego nagłówka.
};

#endif // TEAMMODEL_H
