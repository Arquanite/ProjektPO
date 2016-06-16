#include "selectumpiredialog.h"
#include "ui_selectumpiredialog.h"

SelectUmpireDialog::SelectUmpireDialog(QList<QString> NazwySedziow, QWidget *parent) : QDialog(parent), ui(new Ui::SelectUmpireDialog){
    ui->setupUi(this);
    m_JudgeModel = new QStringListModel();
    m_JudgeModel->setStringList(QStringList(NazwySedziow));
    ui->WidokSedziow->setModel(m_JudgeModel);
    connect(ui->OK, SIGNAL(clicked(bool)), this, SLOT(Sprawdz()));
    connect(ui->Anuluj, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(ui->WidokSedziow, SIGNAL(clicked(QModelIndex)), this, SLOT(ZmianaZaznaczenia(QModelIndex)));
}

SelectUmpireDialog::~SelectUmpireDialog(){
    delete ui;
}

void SelectUmpireDialog::Sprawdz(){
    if(m_Zaznaczenie == -1) QMessageBox::warning(this, "Błąd", "Musisz wybrać sędziego!");
    else {
        emit WybierzSedziego(m_JudgeModel->stringList().at(m_Zaznaczenie));
        accept();
    }
}

void SelectUmpireDialog::ZmianaZaznaczenia(QModelIndex index){
    m_Zaznaczenie = index.row();
}
