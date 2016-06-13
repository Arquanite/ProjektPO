#include "selectteamdialog.h"
#include "ui_selectteamdialog.h"

SelectTeamDialog::SelectTeamDialog(QList<QString> NazwyDruzyn, QWidget *parent) : QDialog(parent), ui(new Ui::SelectTeamDialog){
    ui->setupUi(this);
    m_TeamModel = new QStringListModel();
    m_TeamModel->setStringList(QStringList(NazwyDruzyn));
    ui->WidokDruzyn->setModel(m_TeamModel);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(ui->WidokDruzyn, SIGNAL(clicked(QModelIndex)), this, SLOT(ZmianaZaznaczenia(QModelIndex)));
}

SelectTeamDialog::~SelectTeamDialog(){
    delete ui;
}

void SelectTeamDialog::Sprawdz(){
    if(m_Zaznaczenie == -1) QMessageBox::warning(this, "Błąd", "Musisz wybrać drużynę!");
    else{
        emit WybierzDruzyne(m_TeamModel->stringList().at(m_Zaznaczenie));
        accept();
    }
}

void SelectTeamDialog::ZmianaZaznaczenia(QModelIndex index){
    m_Zaznaczenie = index.row();
}
