#include "matchmodel.h"

MatchModel::MatchModel(const ListaSpotkan *Spotkania, QObject *parent) : QAbstractTableModel(parent), m_Spotkania(Spotkania){

}

int MatchModel::rowCount(const QModelIndex &parent) const {
    if(parent.isValid()) return 0;

    int rozmiar = 0;
    rozmiar += m_Spotkania->ListaSiatkowkaPlazowa.size();
    rozmiar += m_Spotkania->ListaPrzeciaganieLiny.size();
    rozmiar += m_Spotkania->ListaDwaOgnie.size();

    return rozmiar;
}

int MatchModel::columnCount(const QModelIndex &parent) const {
    if(parent.isValid()) return 0;

    return 7;
}

QVariant MatchModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid()) return QVariant();
    if(role != Qt::DisplayRole) return QVariant();

    int A, B;
    A = m_Spotkania->ListaSiatkowkaPlazowa.size();
    B = m_Spotkania->ListaPrzeciaganieLiny.size() + A;

    QString Konkurencja;
    const MeczDruzynowy *M;
    int row = index.row();

    if(index.row() < A){
        M = &m_Spotkania->ListaSiatkowkaPlazowa.at(row);
        Konkurencja = "Siatkówka Plażowa";
    }
    else if(index.row() >= A && index.row() < B){
        row = index.row() - A;
        M = &m_Spotkania->ListaPrzeciaganieLiny.at(row);
        Konkurencja = "Przeciąganie Liny";
    }
    else if(index.row() >= B){
        row = index.row() - B;
        M = &m_Spotkania->ListaDwaOgnie.at(row);
        Konkurencja = "Dwa Ognie";
    }

    if(index.column() == 0) return M->Gospodarz();
    else if(index.column() == 1) return M->Gosc();
    else if(index.column() == 2) return M->Wynik();
    else if(index.column() == 3) return Konkurencja;
    else if(index.column() == 4) return M->Sedzia();
    else if(const SiatkowkaPlazowa *S = dynamic_cast<const SiatkowkaPlazowa*>(M)){
        if(index.column() == 5) return S->SedziaPomocniczy1();
        return S->SedziaPomocniczy2();
    }
    return QVariant();
}

QVariant MatchModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Vertical) return section+1;
    if(orientation == Qt::Horizontal){
        switch (section) {
        case 0:
            return tr("Drużyna Gospodarza");
            break;
        case 1:
            return tr("Drużyna Gościa");
            break;
        case 2:
            return tr("Wynik");
            break;
        case 3:
            return tr("Konkurencja");
            break;
        case 4:
            return tr("Sędzia Główny");
            break;
        case 5:
            return tr("Sędzia Pomocniczy 1");
            break;
        case 6:
            return tr("Sędzia Pomocniczy 2");
            break;
        default:
            break;
        }
    }
    return QVariant();
}

void MatchModel::Init(){
    int rozmiar = 0;
    rozmiar += m_Spotkania->ListaSiatkowkaPlazowa.size();
    rozmiar += m_Spotkania->ListaPrzeciaganieLiny.size();
    rozmiar += m_Spotkania->ListaDwaOgnie.size();
    beginInsertRows(QModelIndex(), 0, rozmiar-1);
    endInsertRows();
}
