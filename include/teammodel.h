#ifndef TEAMMODEL_H
#define TEAMMODEL_H

#include <QAbstractTableModel>
#include "listadruzyn.h"

class TeamModel : public QAbstractTableModel {
    Q_OBJECT
private:
    const ListaDruzyn *m_Druzyny;
    const int m_LiczbaZawodnikow;
public:
    explicit TeamModel(const ListaDruzyn *Druzyny, int LiczbaOsobWDruzynie, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    void AddRow();
    void DeleteRow(int index);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // TEAMMODEL_H
