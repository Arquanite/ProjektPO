#ifndef UMPIREMODEL_H
#define UMPIREMODEL_H

#include <QAbstractTableModel>
#include "listasedziow.h"

/**
 * @brief Model przetwarzający dane sędziów.
 *
 * Tworzy tabelę, w której w każym wierszu znajdują się dane o innym meczu.
 * Tworzy 4 kolumny, znajdują się w nich kolejno: nazwisko, imię,
 * konkurencja i typ sędziego.
 * imiona i nazwiska zawodników.
 *
 * @see MatchModel
 * @see TeamModel
 */
class UmpireModel : public QAbstractTableModel {
    Q_OBJECT
private:
    const ListaSedziow *m_Sedziowie;
public:
    /**
     * @brief Konstruktor
     * @param Spotkania Lista wszystkich drużyn w zawodach.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit UmpireModel(const ListaSedziow *Sedziowie, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override; ///< Zwraca ilość wierszy.
    int columnCount(const QModelIndex &parent = QModelIndex()) const override; ///< Zwraca ilość kolumn.

    void AddRow(); ///< Dodaje nowy wiersz.
    void DeleteRow(int index); ///< Usuwa wiersz o podanym indeksie.

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; ///< Zwraca dane znajdujące się na polu o konkretnym indeksie.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override; ///< Zwraca dane określonego nagłówka.
};

#endif // UMPIREMODEL_H
