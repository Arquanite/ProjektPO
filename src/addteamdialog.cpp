#include "addteamdialog.h"
#include "ui_addteamdialog.h"

#include <QDebug>

AddTeamDialog::AddTeamDialog(QWidget *parent, int LiczbaZawodnikow)
    : QDialog(parent), m_LiczbaZawodnikow(LiczbaZawodnikow), ui(new Ui::AddTeamDialog){
    ui->setupUi(this);
    ui->Zawodnicy->setRowCount(m_LiczbaZawodnikow);
    ui->Zawodnicy->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

AddTeamDialog::~AddTeamDialog(){
    delete ui;
}

void AddTeamDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else{
        QMessageBox::warning(this, "Błąd", "Drużyna o takiej samej nazwie już istnieje!");
    }
}

void AddTeamDialog::Sprawdz(){
    QString Nazwa = ui->NazwaDruzyny->text();
    if(Nazwa.isEmpty()){
        QMessageBox::warning(this, "Błąd", "Musisz podać nazwę drużyny!");
        return;
    }
    m_Konkurencja = ui->Konkurencja->currentIndex();
    QList<Zawodnik> Zawodnicy;
    for(int i=0; i<ui->Zawodnicy->rowCount(); i++){
        QTableWidgetItem *A = ui->Zawodnicy->item(i, 0);
        QTableWidgetItem *B = ui->Zawodnicy->item(i, 1);
        if(!A || !B){
            QMessageBox::warning(this, "Błąd", "Musisz wypełnić wszystkie pola!");
            return;
        }
        Zawodnik Andrzej(ui->Zawodnicy->item(i, 1)->text(), ui->Zawodnicy->item(i, 0)->text());
        Zawodnicy.append(Andrzej);
    }
    m_Druzyna = Druzyna(Nazwa, Zawodnicy);
    emit Dodaj(m_Druzyna, m_Konkurencja);
}
