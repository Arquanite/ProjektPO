#include "competitionmanager.h"
#include "ui_competitionmanager.h"

#include <QDebug>

CompetitionManager::CompetitionManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::CompetitionManager) {
    ui->setupUi(this);
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    UtworzZawody();

    //ui->statusBar->addPermanentWidget(new QLabel("lolxd"));
    //ui->statusBar->addPermanentWidget(new QProgressBar());

    connect(ui->actionZapisz, SIGNAL(triggered(bool)), this, SLOT(Zapisz()));
    connect(ui->actionZapisz_jako, SIGNAL(triggered(bool)), this, SLOT(ZapiszJako()));
    connect(ui->actionWczytaj, SIGNAL(triggered(bool)), this, SLOT(Otworz()));
}

CompetitionManager::~CompetitionManager(){
    delete m_TeamModel;
    delete m_TeamProxyModel;
    delete m_JudgeModel;
    delete m_JudgeProxyModel;
    delete m_MatchModel;
    delete m_MatchProxyModel;
    delete m_Zawody;
    delete ui;
}

void CompetitionManager::UtworzZawody(){
    m_Zawody = new Zawody(5);

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

void CompetitionManager::on_actionDodaj_sedziego_triggered(){
    AddJudgeDialog Dialog;
    connect(&Dialog, SIGNAL(DodajSedziego(Sedzia,int,bool)), this, SLOT(DodajSedziego(Sedzia,int,bool)));
    connect(this, SIGNAL(DodanoSedziego(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy){
    if(m_Zawody->ZarejestrujSedziego(NowySedzia, Konkurencja, Pomocniczy)){
        m_JudgeModel->AddRow();
        emit DodanoSedziego(true);
    }
    else {
        emit DodanoSedziego(false);
    }
}


void CompetitionManager::on_actionUsun_sedziego_triggered(){
    QList<QString> Sedziowie;
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaPomocniczy.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaPrzeciaganieLinyGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaDwaOgnieGlowny.keys());
    qSort(Sedziowie);
    DeleteJudgeDialog Dialog(Sedziowie, this);
    connect(&Dialog, SIGNAL(UsunSedziego(QString)), this, SLOT(UsunSedziego(QString)));
    connect(this, SIGNAL(UsunietoSedziego(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::UsunSedziego(QString Nazwa){
    QList<QString> Sedziowie;
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaPomocniczy.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaPrzeciaganieLinyGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaDwaOgnieGlowny.keys());
    int index = Sedziowie.indexOf(Nazwa);
    if(m_Zawody->UsunSedziego(Nazwa)){
        m_JudgeModel->DeleteRow(index);
        emit UsunietoSedziego(true);
    }
    else {
        emit UsunietoSedziego(false);
    }
}

void CompetitionManager::on_actionWygeneruj_Druzyny_triggered(){
    GenerateTeamsDialog Dialog(this);
    connect(&Dialog, SIGNAL(GenerujDruzyny(int,int)), this, SLOT(GenerujDruzyny(int,int)));
    connect(this, SIGNAL(WygenerowanoDruzyny(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::GenerujDruzyny(int Ilosc, int Konkurencje){
    int Liczba;
    Liczba = Ilosc;
    if(Konkurencje & 0x01){
        m_Zawody->GenerujDruzyny(Ilosc, 0);
        while(Liczba--) m_TeamModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x02){
        m_Zawody->GenerujDruzyny(Ilosc, 1);
        while(Liczba--) m_TeamModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x04){
        m_Zawody->GenerujDruzyny(Ilosc, 2);
        while(Liczba--) m_TeamModel->AddRow();
    }
    emit WygenerowanoDruzyny(true);
}

int CompetitionManager::Konkurencja(Druzyna D){
    int Konkurencja;
    if(m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.count(D.Nazwa())) Konkurencja = 0;
    if(m_Zawody->Druzyny()->ListaPrzeciaganieLiny.count(D.Nazwa())) Konkurencja = 1;
    if(m_Zawody->Druzyny()->ListaDwaOgnie.count(D.Nazwa())) Konkurencja = 2;
    return Konkurencja;
}

void CompetitionManager::on_actionWygeneruj_Sedziow_triggered(){
    GenerateJugdeDialog Dialog(this);
    connect(&Dialog, SIGNAL(GenerujSedziow(int,int)), this, SLOT(GenerujSedziow(int,int)));
    connect(this, SIGNAL(WygenerowanoSedziow(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::GenerujSedziow(int Ilosc, int Konkurencje){
    int Liczba;
    Liczba = Ilosc;
    if(Konkurencje & 0x01){
        if(m_Zawody->GenerujSedziow(Ilosc, 0)) while(Liczba--) m_JudgeModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x02){
        if(m_Zawody->GenerujSedziow(Ilosc, 0, true)) while(Liczba--) m_JudgeModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x04){
        if(m_Zawody->GenerujSedziow(Ilosc, 1)) while(Liczba--) m_JudgeModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x08){
        if(m_Zawody->GenerujSedziow(Ilosc, 2)) while(Liczba--) m_JudgeModel->AddRow();
    }
    emit WygenerowanoSedziow(true);
}

void CompetitionManager::on_actionStan_triggered(){
    State Dialog;
    Dialog.exec();
}

void CompetitionManager::on_actionRozegraj_Mecze_triggered(){
    GenerateMatchScores Dialog;
    if(Dialog.exec()) m_Zawody->RozegrajMecze();
}

void CompetitionManager::on_actionZaplanuj_spotkania_triggered(){
    PlanMatchesDialog Dialog;
    if(Dialog.exec()) m_Zawody->ZaplanujSpotkania();
    m_MatchModel->Init();
}

void CompetitionManager::on_actionEdytuj_druzyne_triggered(){

}

void CompetitionManager::EdytujDruzyne(Druzyna StaraDruzyna, Druzyna NowaDruzyna, int Konkurencja){
    if(StaraDruzyna.Nazwa() == NowaDruzyna.Nazwa()){
        m_Zawody->UsunDruzyne(StaraDruzyna.Nazwa());
        m_Zawody->ZarejestrujDruzyne(NowaDruzyna, Konkurencja);
    }
    else {
        if(m_Zawody->ZarejestrujDruzyne(NowaDruzyna, Konkurencja)){
            m_Zawody->UsunDruzyne(StaraDruzyna.Nazwa());
        }
        else{
            emit EdytowanoDruzyne(false);
            return;
        }
    }
    emit EdytowanoDruzyne(true);
}
void CompetitionManager::on_widokDruzyn_doubleClicked(const QModelIndex &index){
    QString Nazwa = m_TeamProxyModel->data(m_TeamProxyModel->index(index.row(), 0)).toString();
    Druzyna D;
    if(m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.count(Nazwa)) D = m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.value(Nazwa);
    if(m_Zawody->Druzyny()->ListaPrzeciaganieLiny.count(Nazwa)) D = m_Zawody->Druzyny()->ListaPrzeciaganieLiny.value(Nazwa);
    if(m_Zawody->Druzyny()->ListaDwaOgnie.count(Nazwa)) D = m_Zawody->Druzyny()->ListaDwaOgnie.value(Nazwa);
    EditTeamDialog Dialog(this, D, Konkurencja(D));
    connect(&Dialog, SIGNAL(Edytuj(Druzyna,Druzyna,int)), this, SLOT(EdytujDruzyne(Druzyna,Druzyna,int)));
    connect(this, SIGNAL(EdytowanoDruzyne(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}


bool CompetitionManager::Zapisz(){
    if(m_NazwaPliku.isEmpty()) ZapiszJako();
    QFile Plik(m_NazwaPliku);
    Plik.open(QIODevice::WriteOnly);
    QDataStream out(&Plik);
    out<<*m_Zawody;
    Plik.flush();
    Plik.close();
    return true;
}

bool CompetitionManager::ZapiszJako(){
    m_NazwaPliku = QFileDialog::getSaveFileName();
}

bool CompetitionManager::Otworz(){
    m_NazwaPliku = QFileDialog::getOpenFileName();
    QFile Plik(m_NazwaPliku);
    Plik.open(QIODevice::ReadOnly);
    QDataStream in(&Plik);
    in>>*m_Zawody;
    Plik.close();

    delete m_TeamModel;
    m_TeamModel = new TeamModel(m_Zawody->Druzyny(), m_Zawody->LiczbaOsob());
    m_TeamProxyModel->setSourceModel(m_TeamModel);

    delete m_JudgeModel;
    m_JudgeModel = new JudgeModel(m_Zawody->Sedziowie());
    m_JudgeProxyModel->setSourceModel(m_JudgeModel);

    delete m_MatchModel;
    m_MatchModel = new MatchModel(m_Zawody->Spotkania());
    m_MatchProxyModel->setSourceModel(m_MatchModel);
}
