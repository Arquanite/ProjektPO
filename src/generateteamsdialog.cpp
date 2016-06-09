#include "generateteamsdialog.h"
#include "ui_generateteamsdialog.h"

GenerateTeamsDialog::GenerateTeamsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GenerateTeamsDialog){
    ui->setupUi(this);
    connect(ui->SiatkowkaPlazowa, SIGNAL(stateChanged(int)), this, SLOT(ObliczWartosc()));
    connect(ui->PrzeciaganieLiny, SIGNAL(stateChanged(int)), this, SLOT(ObliczWartosc()));
    connect(ui->DwaOgnie, SIGNAL(stateChanged(int)), this, SLOT(ObliczWartosc()));
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

GenerateTeamsDialog::~GenerateTeamsDialog(){
    delete ui;
}

void GenerateTeamsDialog::on_Ilosc_valueChanged(int arg1){
    m_Liczba = arg1;
    ObliczWartosc();
}

int GenerateTeamsDialog::ObliczWartosc(){
    int ilosc = 0;
    if(ui->SiatkowkaPlazowa->isChecked()) ilosc += m_Liczba;
    if(ui->PrzeciaganieLiny->isChecked()) ilosc += m_Liczba;
    if(ui->DwaOgnie->isChecked()) ilosc += m_Liczba;
    ui->Uwaga->setText(QString("Uwaga! Wygenerowane zostanie %1 drużyn.").arg(ilosc));
    return ilosc;
}

void GenerateTeamsDialog::Sprawdz(){
    if(ObliczWartosc() == 0){
        QMessageBox::warning(this, "Błąd", "Próbujesz wygenerować 0 drużyn!");
        return;
    }
    int Konkurencje = 0;
    if(ui->SiatkowkaPlazowa->isChecked()) Konkurencje += 0x01;
    if(ui->PrzeciaganieLiny->isChecked()) Konkurencje += 0x02;
    if(ui->DwaOgnie->isChecked()) Konkurencje += 0x04;
    emit GenerujDruzyny(m_Liczba, Konkurencje);
}

void GenerateTeamsDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else{
        QMessageBox::warning(this, "Błąd", QString("Wystąpił błąd ale nikt nie ujrzy tego komunikatu ponieważ zawiesił mu się program :<"));
        done(2);
    }
}
