#ifndef JUDGEMODEL_H
#define JUDGEMODEL_H

#include <QAbstractTableModel>
#include "listasedziow.h"

class JudgeModel : public QAbstractTableModel {
    Q_OBJECT
private:
    const ListaSedziow *m_Sedziowie;
public:
    explicit JudgeModel(const ListaSedziow *Sedziowie, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    void AddRow();
    void DeleteRow(int index);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // JUDGEMODEL_H
