#include "betterproxymodel.h"

BetterProxyModel::BetterProxyModel(){

}

QVariant BetterProxyModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal) return QSortFilterProxyModel::headerData(section, orientation, role);
    if(orientation == Qt::Vertical) return section+1;
    return QVariant();
}
