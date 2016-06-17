#ifndef MATCHMODEL_H
#define MATCHMODEL_H

#include <QAbstractItemModel>
#include "listaspotkan.h"
#include "listadruzyn.h"

/**
 * @brief Model przetwarzający dane spotkań.
 *
 * Tworzy tabelę, w której w każym wierszu znajdują się dane o innym meczu.
 * Tworzy siedem kolumn, znajdują się w nich kolejno: nazwa gospodarza, nazwa gościa,
 * wynik, konkurencja, nazwisko i imię sędziego głównego, pomocniczego oraz drugiego pomocniczego.
 *
 * @see TeamModel
 * @see UmpireModel
 */
class MatchModel : public QAbstractTableModel {
    Q_OBJECT
private:
    const ListaSpotkan *m_Spotkania;
public:
    /**
     * @brief Konstruktor
     * @param Spotkania Lista wszystkich meczy w zawodach.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit MatchModel(const ListaSpotkan *Spotkania, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override; ///< Zwraca ilość wierszy.
    int columnCount(const QModelIndex &parent = QModelIndex()) const override; ///< Zwraca ilość kolumn.

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; ///< Zwraca dane znajdujące się na polu o konkretnym indeksie.
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override; ///< Zwraca dane określonego nagłówka.

    void Init(); ///Wypełnia pusty model danymi, używane przy wczytywaniu z pliku.
};

#endif // MATCHMODEL_H
