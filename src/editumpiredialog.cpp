#include "editumpiredialog.h"
#include "ui_editumpiredialog.h"

EditUmpireDialog::EditUmpireDialog(QWidget *parent, Sedzia sedzia, int Konkurencja, bool Pomocniczy)
    : QDialog(parent), m_Sedzia(sedzia), m_Konkurencja(Konkurencja), m_Pomocniczy(Pomocniczy), ui(new Ui::EditUmpireDialog){
    ui->setupUi(this);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));

    ui->Imie->setText(m_Sedzia.Imie());
    ui->Nazwisko->setText(m_Sedzia.Nazwisko());
    ui->Konkurencja->setCurrentIndex(m_Konkurencja);
    ui->Pomocniczy->setChecked(m_Pomocniczy);
}

EditUmpireDialog::~EditUmpireDialog(){
    delete ui;
}

void EditUmpireDialog::Sprawdz(){
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
    emit EdytujSedziego(m_Sedzia, Andrzej, ui->Konkurencja->currentIndex(), ui->Pomocniczy->isChecked());
}

void EditUmpireDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else {
        QMessageBox::warning(this, "Błąd", "Osoba o tym samym imieniu i nazwisku już istnieje!");
    }
}
