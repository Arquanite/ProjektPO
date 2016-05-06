#ifndef BETTERPROXYMODEL_H
#define BETTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class BetterProxyModel : public QSortFilterProxyModel
{
public:
    BetterProxyModel();
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // BETTERPROXYMODEL_H
