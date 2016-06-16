#include "generateumpiredialog.h"
#include "ui_generateumpiredialog.h"

GenerateUmpireDialog::GenerateUmpireDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GenerateUmpireDialog){
    ui->setupUi(this);
    connect(ui->SiatkowkaPlazowaG, SIGNAL(stateChanged(int)), this, SLOT(ObliczWartosc()));
    connect(ui->SiatkowkaPlazowaP, SIGNAL(stateChanged(int)), this, SLOT(ObliczWartosc()));
    connect(ui->PrzeciaganieLinyG, SIGNAL(stateChanged(int)), this, SLOT(ObliczWartosc()));
    connect(ui->DwaOgnieG, SIGNAL(stateChanged(int)), this, SLOT(ObliczWartosc()));
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

GenerateUmpireDialog::~GenerateUmpireDialog(){
    delete ui;
}

void GenerateUmpireDialog::on_Ilosc_valueChanged(int arg1){
    m_Liczba = arg1;
    ObliczWartosc();
}

int GenerateUmpireDialog::ObliczWartosc(){
    int ilosc = 0;
    if(ui->SiatkowkaPlazowaG->isChecked()) ilosc += m_Liczba;
    if(ui->SiatkowkaPlazowaP->isChecked()) ilosc += m_Liczba;
    if(ui->PrzeciaganieLinyG->isChecked()) ilosc += m_Liczba;
    if(ui->DwaOgnieG->isChecked()) ilosc += m_Liczba;
    ui->Uwaga->setText(QString("Uwaga! Wygenerowane zostanie %1 sedziów.").arg(ilosc));
    return ilosc;
}

void GenerateUmpireDialog::Sprawdz(){
    if(ObliczWartosc() == 0){
        QMessageBox::warning(this, "Błąd", "Próbujesz wygenerować 0 sędziów!");
        return;
    }
    int Konkurencje = 0;
    if(ui->SiatkowkaPlazowaG->isChecked()) Konkurencje += 0x01;
    if(ui->SiatkowkaPlazowaP->isChecked()) Konkurencje += 0x02;
    if(ui->PrzeciaganieLinyG->isChecked()) Konkurencje += 0x04;
    if(ui->DwaOgnieG->isChecked()) Konkurencje += 0x08;
    emit GenerujSedziow(m_Liczba, Konkurencje);
}

void GenerateUmpireDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else{
        QMessageBox::warning(this, "Błąd", QString("Wystąpił błąd ale nikt nie ujrzy tego komunikatu ponieważ zawiesił mu się program :<"));
        done(2);
    }
}
