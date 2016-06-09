#include "deletejudgedialog.h"
#include "ui_deletejudgedialog.h"

DeleteJudgeDialog::DeleteJudgeDialog(QList<QString> NazwySedziow, QWidget *parent) : QDialog(parent), ui(new Ui::DeleteJudgeDialog){
    ui->setupUi(this);
    m_JudgeModel = new QStringListModel();
    m_JudgeModel->setStringList(QStringList(NazwySedziow));
    ui->WidokSedziow->setModel(m_JudgeModel);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(ui->WidokSedziow, SIGNAL(clicked(QModelIndex)), this, SLOT(ZmianaZaznaczenia(QModelIndex)));
}

DeleteJudgeDialog::~DeleteJudgeDialog(){
    delete ui;
}

void DeleteJudgeDialog::UdaoSiem(bool Odpowiedz){
    if(Odpowiedz) accept();
    else {
        QMessageBox::warning(this, "Błąd", "Wystąpił błąd, spróbuj jeszcze raz!");
    }
}

void DeleteJudgeDialog::Sprawdz(){
    if(m_Zaznaczenie == -1) QMessageBox::warning(this, "Błąd", "Musisz wybrać, którego sedziego chesz usunąć!");
    else emit UsunSedziego(m_JudgeModel->stringList().at(m_Zaznaczenie));
}

void DeleteJudgeDialog::ZmianaZaznaczenia(QModelIndex index){
    m_Zaznaczenie = index.row();
}
