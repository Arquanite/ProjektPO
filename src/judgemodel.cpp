#include "judgemodel.h"

JudgeModel::JudgeModel(const ListaSedziow *Sedziowie, QObject *parent) : QAbstractTableModel(parent), m_Sedziowie(Sedziowie){

}

int JudgeModel::rowCount(const QModelIndex &parent) const {
    if(parent.isValid())   return 0;

    int rozmiar = 0;
    rozmiar += m_Sedziowie->ListaSiatkowkaPlazowaGlowny.size();
    rozmiar += m_Sedziowie->ListaSiatkowkaPlazowaPomocniczy.size();
    rozmiar += m_Sedziowie->ListaPrzeciaganieLinyGlowny.size();
    rozmiar += m_Sedziowie->ListaDwaOgnieGlowny.size();

    return rozmiar;
}

int JudgeModel::columnCount(const QModelIndex &parent) const {
    if(parent.isValid()) return 0;
    return 4;
}

void JudgeModel::AddRow(){
    beginInsertRows(QModelIndex(), 0, 0);
    endInsertRows();
}

void JudgeModel::DeleteRow(int index){
    beginRemoveRows(QModelIndex(), index, index);
    endRemoveRows();
}

QVariant JudgeModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid()) return QVariant();
    if(role != Qt::DisplayRole) return QVariant();

    int A, B, C;
    A = m_Sedziowie->ListaSiatkowkaPlazowaGlowny.size();
    B = m_Sedziowie->ListaSiatkowkaPlazowaPomocniczy.size() + A;
    C = m_Sedziowie->ListaPrzeciaganieLinyGlowny.size() + B;

    QString Konkurencja, Typ;
    Sedzia S;
    QList<QString> L;
    int row = index.row();

    if(index.row() < A){
        L = m_Sedziowie->ListaSiatkowkaPlazowaGlowny.keys();
        S = m_Sedziowie->ListaSiatkowkaPlazowaGlowny.value(L.value(row));
        Konkurencja = "Siatkówka Plażowa";
        Typ = "Sędzia Główny";
    }
    else if(index.row() >= A && index.row() < B){
        row = index.row() - A;
        L = m_Sedziowie->ListaSiatkowkaPlazowaPomocniczy.keys();
        S = m_Sedziowie->ListaSiatkowkaPlazowaPomocniczy.value(L.value(row));
        Konkurencja = "Siatkówka Plażowa";
        Typ = "Sędzia Pomocniczy";
    }
    else if(index.row() >= B && index.row() < C){
        row = index.row() - B;
        L = m_Sedziowie->ListaPrzeciaganieLinyGlowny.keys();
        S = m_Sedziowie->ListaPrzeciaganieLinyGlowny.value(L.value(row));
        Konkurencja = "Przeciąganie Liny";
        Typ = "Sędzia Główny";
    }
    else if(index.row() >= B){
        row = index.row() - C;
        L = m_Sedziowie->ListaDwaOgnieGlowny.keys();
        S = m_Sedziowie->ListaDwaOgnieGlowny.value(L.value(row));
        Konkurencja = "Dwa Ognie";
        Typ = "Sędzia Główny";
    }

    switch (index.column()) {
    case 0:
        return S.Nazwisko();
        break;
    case 1:
        return S.Imie();
        break;
    case 2:
        return Konkurencja;
        break;
    case 3:
        return Typ;
        break;
    default:
        return QVariant();
        break;
    }

}

QVariant JudgeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role != Qt::DisplayRole) return QVariant();
    if(orientation == Qt::Horizontal){
        if(section == 0) return tr("Nazwisko");
        if(section == 1) return tr("Imie");
        if(section == 2) return tr("Konkurencja");
        if(section == 3) return tr("Typ");
    }
    return section+1;
}
