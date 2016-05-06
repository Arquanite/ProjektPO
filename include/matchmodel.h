#ifndef MATCHMODEL_H
#define MATCHMODEL_H

#include <QAbstractItemModel>
#include "listaspotkan.h"

class MatchModel : public QAbstractTableModel {
    Q_OBJECT
private:
    const ListaSpotkan *m_Spotkania;
public:
    explicit MatchModel(const ListaSpotkan *Spotkania, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // MATCHMODEL_H
