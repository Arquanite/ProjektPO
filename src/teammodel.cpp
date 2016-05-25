#include "teammodel.h"

TeamModel::TeamModel(const ListaDruzyn *Druzyny, QObject *parent) : QAbstractTableModel(parent), m_Druzyny(Druzyny){

}

int TeamModel::rowCount(const QModelIndex &parent) const {
    if(parent.isValid()) return 0;

    int rozmiar = 0;
    rozmiar += m_Druzyny->ListaSiatkowkaPlazowa.size();
    rozmiar += m_Druzyny->ListaPrzeciaganieLiny.size();
    rozmiar += m_Druzyny->ListaDwaOgnie.size();

    return rozmiar;
}

int TeamModel::columnCount(const QModelIndex &parent) const {
    if(parent.isValid()) return 0;

    if(!m_Druzyny->ListaDwaOgnie.empty()) return m_Druzyny->ListaDwaOgnie.first().Zawodnicy().size()+3;
    else return 0;
}

QVariant TeamModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid()) return QVariant();
    if(role != Qt::DisplayRole) return QVariant();

    int A, B;
    A = m_Druzyny->ListaSiatkowkaPlazowa.size();
    B = m_Druzyny->ListaPrzeciaganieLiny.size() + A;

    QString Konkurencja;
    Druzyna D;
    QList<QString> L;
    int row = index.row();

    if(index.row() < A){
        L = m_Druzyny->ListaSiatkowkaPlazowa.keys();
        D = m_Druzyny->ListaSiatkowkaPlazowa.value(L.value(row));
        Konkurencja = "Siatkówka Plażowa";
    }
    else if(index.row() >= A && index.row() < B){
        row = index.row() - A;
        L = m_Druzyny->ListaPrzeciaganieLiny.keys();
        D = m_Druzyny->ListaPrzeciaganieLiny.value(L.value(row));
        Konkurencja = "Przeciąganie Liny";
    }
    else if(index.row() >= B){
        row = index.row() - B;
        L = m_Druzyny->ListaDwaOgnie.keys();
        D = m_Druzyny->ListaDwaOgnie.value(L.value(row));
        Konkurencja = "Dwa Ognie";
    }

    if(index.column() == 0) return D.Nazwa();
    else if(index.column() == 1) return D.Punkty();
    else if(index.column() == 2) return Konkurencja;
    else {
        Zawodnik Z = D.Zawodnicy().at(index.column()-3);
        return Z.Nazwisko() + " " + Z.Imie();
    }
}

QVariant TeamModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Vertical) return section+1;
    if(orientation == Qt::Horizontal){
        if(section == 0) return tr("Nazwa drużyny");
        else if(section == 1) return tr("Punkty");
        else if(section == 2) return tr("Konkurencja");
        else return tr("Zawodnik %1").arg(section-2);
    }
    return QVariant();
}
