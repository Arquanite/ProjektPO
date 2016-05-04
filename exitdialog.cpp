#include "exitdialog.h"
#include "ui_exitdialog.h"

ExitDialog::ExitDialog(QString NazwaPliku, QWidget *parent) : QDialog(parent), ui(new Ui::ExitDialog){
    ui->setupUi(this);
    ui->Tekst_2->setText(tr("W pliku %1 są niezapisane zmiany, zakończenie pracy spowoduje ich utracenie.").arg(NazwaPliku));
    connect(ui->Wyjdz, SIGNAL(clicked(bool)), this, SLOT(Wyjdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(Anuluj()));
    connect(ui->Zapisz, SIGNAL(clicked(bool)), this, SLOT(Zapisz()));
}

ExitDialog::~ExitDialog(){
    delete ui;
}

void ExitDialog::Wyjdz(){
    done(-1);
}

void ExitDialog::Anuluj(){
    done(0);
}

void ExitDialog::Zapisz(){
    done(1);
}
