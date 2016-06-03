#include "addjudgedialog.h"
#include "ui_addjudgedialog.h"

AddJudgeDialog::AddJudgeDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddJudgeDialog){
    ui->setupUi(this);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

AddJudgeDialog::~AddJudgeDialog(){
    delete ui;
}

void AddJudgeDialog::Sprawdz(){
    if(ui->Imie->text().isEmpty()){
        QMessageBox::warning(this, "Błąd", "Sędzia musi mieć imię!");
        return;
    }
    if(ui->Nazwisko->text().isEmpty()){
        QMessageBox::warning(this, "Błąd", "Sędzia musi mieć nazwisko!");
        return;
    }
    if(ui->Konkurencja->currentIndex() != 0 && ui->Pomocniczy->isChecked()){
        QMessageBox::warning(this, "Błąd", "Tylko w siatkówce plażowej występują sędziowie pomocniczy!");
        return;
    }

    Sedzia Andrzej(ui->Imie->text(), ui->Nazwisko->text());
    emit DodajSedziego(Andrzej, ui->Konkurencja->currentIndex(), ui->Pomocniczy->isChecked());
}

void AddJudgeDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else {
        QMessageBox::warning(this, "Błąd", "Osoba o tym samym imieniu i nazwisku już istnieje!");
    }
}
