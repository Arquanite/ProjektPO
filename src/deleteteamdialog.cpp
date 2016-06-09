#include "deleteteamdialog.h"
#include "ui_deleteteamdialog.h"

DeleteTeamDialog::DeleteTeamDialog(QList<QString> NazwyDruzyn, QWidget *parent) : QDialog(parent), ui(new Ui::DeleteTeamDialog){
    ui->setupUi(this);
    m_TeamModel = new QStringListModel();
    m_TeamModel->setStringList(QStringList(NazwyDruzyn));
    ui->WidokDruzyn->setModel(m_TeamModel);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(ui->WidokDruzyn, SIGNAL(clicked(QModelIndex)), this, SLOT(ZmianaZaznaczenia(QModelIndex)));
}

DeleteTeamDialog::~DeleteTeamDialog(){
    delete ui;
}

void DeleteTeamDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else {
        QMessageBox::warning(this, "Błąd", "Wystąpił błąd, spróbuj jeszcze raz!");
    }
}

void DeleteTeamDialog::Sprawdz(){
    if(m_Zaznaczenie == -1) QMessageBox::warning(this, "Błąd", "Musisz wybrać, którą drużynę chesz usunąć!");
    else emit UsunDruzyne(m_TeamModel->stringList().at(m_Zaznaczenie));
}

void DeleteTeamDialog::ZmianaZaznaczenia(QModelIndex index){
    m_Zaznaczenie = index.row();
}
