#include "competitionmanager.h"
#include "ui_competitionmanager.h"

#include <QDebug>

CompetitionManager::CompetitionManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::CompetitionManager) {
    ui->setupUi(this);
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    UtworzZawody();

    //ui->statusBar->addPermanentWidget(new QLabel("lolxd"));
    //ui->statusBar->addPermanentWidget(new QProgressBar());

}

CompetitionManager::~CompetitionManager(){
    delete m_TeamModel;
    delete m_TeamProxyModel;
    delete m_JudgeModel;
    delete m_JudgeProxyModel;
    delete m_MatchModel;
    delete m_MatchProxyModel;
    delete ui;
}

void CompetitionManager::UtworzZawody(){
    m_Zawody = new Zawody(2);
    m_Zawody->GenerujDruzyny(19);
    //m_Zawody.GenerujSedziow(5);
    //m_Zawody.ZaplanujSpotkania();
    //m_Zawody.RozegrajMecze();

    const ListaDruzyn* Druzyny = m_Zawody->Druzyny();
    m_TeamModel = new TeamModel(Druzyny, m_Zawody->LiczbaOsob());
    m_TeamProxyModel = new BetterProxyModel;

    m_TeamProxyModel->setSourceModel(m_TeamModel);
    m_TeamProxyModel->setFilterKeyColumn(2);

    ui->widokDruzyn->setModel(m_TeamProxyModel);
    ui->widokDruzyn->resizeColumnsToContents();
    ui->widokDruzyn->horizontalHeader()->setSectionsMovable(true);
    ui->widokDruzyn->sortByColumn(1, Qt::DescendingOrder);

    const ListaSedziow* Sedziowie = m_Zawody->Sedziowie();
    m_JudgeModel = new JudgeModel(Sedziowie);
    m_JudgeProxyModel = new BetterProxyModel;

    m_JudgeProxyModel->setSourceModel(m_JudgeModel);
    m_JudgeProxyModel->setFilterKeyColumn(2);

    ui->widokSedziow->setModel(m_JudgeProxyModel);
    ui->widokSedziow->resizeColumnsToContents();
    ui->widokSedziow->horizontalHeader()->setSectionsMovable(true);
    ui->widokSedziow->sortByColumn(0, Qt::AscendingOrder);

    const ListaSpotkan* Spotkania = m_Zawody->Spotkania();
    m_MatchModel = new MatchModel(Spotkania);
    m_MatchProxyModel = new BetterProxyModel;

    m_MatchProxyModel->setSourceModel(m_MatchModel);
    m_MatchProxyModel->setFilterKeyColumn(3);

    ui->widokSpotkan->setModel(m_MatchProxyModel);
    ui->widokSpotkan->resizeColumnsToContents();
    ui->widokSpotkan->horizontalHeader()->setSectionsMovable(true);
    ui->widokSpotkan->sortByColumn(2, Qt::AscendingOrder);
}

void CompetitionManager::closeEvent(QCloseEvent *event){
    ExitDialog Dialog("nienazwany", this);
    int x = Dialog.exec();
    switch (x) {
    case -1:
        event->accept();
        break;
    case 0:
        event->ignore();
        break;
    case 1:
        event->accept();
        break;
    }
}

void CompetitionManager::on_Wszystkie_clicked(bool checked){
    QString Filtr = QString();
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_JudgeProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_SiatkowkaPlazowa_clicked(bool checked){
    QString Filtr = "Siatkówka Plażowa";
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_JudgeProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_PrzeciaganieLiny_clicked(bool checked){
    QString Filtr = "Przeciąganie Liny";
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_JudgeProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_DwaOgnie_clicked(bool checked){
    QString Filtr = "Dwa Ognie";
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_JudgeProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_actionDodaj_druzyne_triggered(){
    AddTeamDialog Dialog(this, m_Zawody->LiczbaOsob());
    connect(&Dialog, SIGNAL(Dodaj(Druzyna,int)), this, SLOT(DodajDruzyne(Druzyna,int)));
    connect(this, SIGNAL(UtworzonoDruzyne(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::DodajDruzyne(Druzyna NowaDruzyna, int Konkurencja){
    if(m_Zawody->ZarejestrujDruzyne(NowaDruzyna, Konkurencja)){
        m_TeamModel->AddRow();
        qDebug()<<m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.size();
        emit UtworzonoDruzyne(true);
    }
    else{
        emit UtworzonoDruzyne(false);
    }
}

void CompetitionManager::on_actionUsun_druzyne_triggered(){
    QList<QString> Druzyny;
    Druzyny.append(m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.keys());
    Druzyny.append(m_Zawody->Druzyny()->ListaPrzeciaganieLiny.keys());
    Druzyny.append(m_Zawody->Druzyny()->ListaDwaOgnie.keys());
    qSort(Druzyny);
    DeleteTeamDialog Dialog(Druzyny, this);
    connect(&Dialog, SIGNAL(UsunDruzyne(QString)), this, SLOT(UsunDruzyne(QString)));
    connect(this, SIGNAL(UsunietoDruzyne(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::UsunDruzyne(QString Nazwa){
    QList<QString> Druzyny;
    Druzyny.append(m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.keys());
    Druzyny.append(m_Zawody->Druzyny()->ListaPrzeciaganieLiny.keys());
    Druzyny.append(m_Zawody->Druzyny()->ListaDwaOgnie.keys());
    int index = Druzyny.indexOf(Nazwa);
    if(m_Zawody->UsunDruzyne(Nazwa)){
        m_TeamModel->DeleteRow(index);
        emit UsunietoDruzyne(true);
    }
    else {
        emit UsunietoDruzyne(false);
    }
}
