#include "editteamdialog.h"
#include "ui_editteamdialog.h"

EditTeamDialog::EditTeamDialog(QWidget *parent, Druzyna druzyna, int Konkurencja) : QDialog(parent), m_Druzyna(druzyna), ui(new Ui::EditTeamDialog){
    ui->setupUi(this);
    ui->Zawodnicy->setRowCount(m_Druzyna.Zawodnicy().size());
    ui->Zawodnicy->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));

    ui->NazwaDruzyny->setText(druzyna.Nazwa());
    for(int i=0; i<ui->Zawodnicy->rowCount(); i++){
        ui->Zawodnicy->setItem(i, 0, new QTableWidgetItem(druzyna.Zawodnicy().at(i).Nazwisko()));
        ui->Zawodnicy->setItem(i, 1, new QTableWidgetItem(druzyna.Zawodnicy().at(i).Imie()));
    }
    ui->Konkurencja->setCurrentIndex(Konkurencja);

}

EditTeamDialog::~EditTeamDialog(){
    delete ui;
}

void EditTeamDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else{
        QMessageBox::warning(this, "Błąd", "Drużyna o takiej samej nazwie już istnieje!");
    }
}

void EditTeamDialog::Sprawdz(){
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
    emit Edytuj(m_Druzyna, Druzyna(Nazwa, Zawodnicy), ui->Konkurencja->currentIndex());
}
