#include "competitionmanager.h"
#include "ui_competitionmanager.h"

#include <QDebug>

CompetitionManager::CompetitionManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::CompetitionManager) {
    ui->setupUi(this);
    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    UtworzZawody();

    ui->statusBar->showMessage("Jak widać, działa :D");
    m_StatusBarEtap = new QLabel("Aktualny etap: " + m_Zawody->EtapToString());
    m_StatusBarEtap->setStyleSheet("color: white");
    ui->statusBar->addPermanentWidget(m_StatusBarEtap);
    //ui->statusBar->addPermanentWidget(new QProgressBar());

    connect(ui->actionZapisz, SIGNAL(triggered(bool)), this, SLOT(Zapisz()));
    connect(ui->actionZapisz_jako, SIGNAL(triggered(bool)), this, SLOT(ZapiszJako()));
    connect(ui->actionWczytaj, SIGNAL(triggered(bool)), this, SLOT(Otworz()));
}

CompetitionManager::~CompetitionManager(){
    delete m_TeamModel;
    delete m_TeamProxyModel;
    delete m_UmpireModel;
    delete m_UmpireProxyModel;
    delete m_MatchModel;
    delete m_MatchProxyModel;
    delete m_Zawody;
    delete m_StatusBarEtap;
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
    m_UmpireModel = new UmpireModel(Sedziowie);
    m_UmpireProxyModel = new BetterProxyModel;

    m_UmpireProxyModel->setSourceModel(m_UmpireModel);
    m_UmpireProxyModel->setFilterKeyColumn(2);

    ui->widokSedziow->setModel(m_UmpireProxyModel);
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
    ExitDialog Dialog(m_NazwaPliku, this);
    int x = Dialog.exec();
    switch (x) {
    case -1:
        event->accept();
        break;
    case 0:
        event->ignore();
        break;
    case 1:
        if(Zapisz()) event->accept();
        else event->ignore();
        break;
    }
}

void CompetitionManager::on_Wszystkie_clicked(bool checked){
    QString Filtr = QString();
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_UmpireProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_SiatkowkaPlazowa_clicked(bool checked){
    QString Filtr = "Siatkówka Plażowa";
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_UmpireProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_PrzeciaganieLiny_clicked(bool checked){
    QString Filtr = "Przeciąganie Liny";
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_UmpireProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_DwaOgnie_clicked(bool checked){
    QString Filtr = "Dwa Ognie";
    if(checked){
        m_TeamProxyModel->setFilterFixedString(Filtr);
        m_UmpireProxyModel->setFilterFixedString(Filtr);
        m_MatchProxyModel->setFilterFixedString(Filtr);
    }
}

void CompetitionManager::on_actionDodaj_druzyne_triggered(){
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
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
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
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
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
    AddUmpireDialog Dialog;
    connect(&Dialog, SIGNAL(DodajSedziego(Sedzia,int,bool)), this, SLOT(DodajSedziego(Sedzia,int,bool)));
    connect(this, SIGNAL(DodanoSedziego(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy){
    if(m_Zawody->ZarejestrujSedziego(NowySedzia, Konkurencja, Pomocniczy)){
        m_UmpireModel->AddRow();
        emit DodanoSedziego(true);
    }
    else {
        emit DodanoSedziego(false);
    }
}


void CompetitionManager::on_actionUsun_sedziego_triggered(){
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
    QList<QString> Sedziowie;
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaPomocniczy.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaPrzeciaganieLinyGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaDwaOgnieGlowny.keys());
    qSort(Sedziowie);
    DeleteUmpireDialog Dialog(Sedziowie, this);
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
        m_UmpireModel->DeleteRow(index);
        emit UsunietoSedziego(true);
    }
    else {
        emit UsunietoSedziego(false);
    }
}

void CompetitionManager::on_actionEdytuj_dane_sedziego_triggered(){
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
    QList<QString> Sedziowie;
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaPomocniczy.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaPrzeciaganieLinyGlowny.keys());
    Sedziowie.append(m_Zawody->Sedziowie()->ListaDwaOgnieGlowny.keys());
    qSort(Sedziowie);
    SelectUmpireDialog Dialog(Sedziowie, this);
    connect(&Dialog, SIGNAL(WybierzSedziego(QString)), this, SLOT(WybranoSedziegoDoEdycji(QString)));
    Dialog.exec();
}

void CompetitionManager::EdytujSedziego(Sedzia StarySedzia, Sedzia NowySedzia, int Konkurencja, bool Pomocniczy){
    if((StarySedzia.Nazwisko() + " " + StarySedzia.Imie()) == (NowySedzia.Nazwisko() + " " + NowySedzia.Imie())){
        m_Zawody->UsunSedziego(StarySedzia.Nazwisko() + " " + StarySedzia.Imie());
        m_Zawody->ZarejestrujSedziego(NowySedzia, Konkurencja, Pomocniczy);
    }
    else {
        if(m_Zawody->ZarejestrujSedziego(NowySedzia, Konkurencja, Pomocniczy)){
            m_Zawody->UsunSedziego(StarySedzia.Nazwisko() + " " + StarySedzia.Imie());
        }
        else{
            emit EdytowanoSedziego(false);
            return;
        }
    }
    emit EdytowanoSedziego(true);
}

void CompetitionManager::WybranoSedziegoDoEdycji(QString Nazwa){
    Sedzia S;
    int Konkurencja;
    bool Pomocniczy = false;
    if(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaGlowny.count(Nazwa)){
        S = m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaGlowny.value(Nazwa);
        Konkurencja = 0;
    }
    if(m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaPomocniczy.count(Nazwa)){
        S = m_Zawody->Sedziowie()->ListaSiatkowkaPlazowaPomocniczy.value(Nazwa);
        Konkurencja = 0;
        Pomocniczy = true;
    }
    if(m_Zawody->Sedziowie()->ListaPrzeciaganieLinyGlowny.count(Nazwa)){
        S = m_Zawody->Sedziowie()->ListaPrzeciaganieLinyGlowny.value(Nazwa);
        Konkurencja = 1;
    }
    if(m_Zawody->Sedziowie()->ListaDwaOgnieGlowny.count(Nazwa)){
        S = m_Zawody->Sedziowie()->ListaDwaOgnieGlowny.value(Nazwa);
        Konkurencja = 2;
    }
    EditUmpireDialog Dialog(this, S, Konkurencja, Pomocniczy);
    connect(&Dialog, SIGNAL(EdytujSedziego(Sedzia,Sedzia,int,bool)), this, SLOT(EdytujSedziego(Sedzia,Sedzia,int,bool)));
    connect(this, SIGNAL(EdytowanoSedziego(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::on_actionWygeneruj_Druzyny_triggered(){
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
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
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
    GenerateUmpireDialog Dialog(this);
    connect(&Dialog, SIGNAL(GenerujSedziow(int,int)), this, SLOT(GenerujSedziow(int,int)));
    connect(this, SIGNAL(WygenerowanoSedziow(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::GenerujSedziow(int Ilosc, int Konkurencje){
    int Liczba;
    Liczba = Ilosc;
    if(Konkurencje & 0x01){
        if(m_Zawody->GenerujSedziow(Ilosc, 0)) while(Liczba--) m_UmpireModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x02){
        if(m_Zawody->GenerujSedziow(Ilosc, 0, true)) while(Liczba--) m_UmpireModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x04){
        if(m_Zawody->GenerujSedziow(Ilosc, 1)) while(Liczba--) m_UmpireModel->AddRow();
    }
    Liczba = Ilosc;
    if(Konkurencje & 0x08){
        if(m_Zawody->GenerujSedziow(Ilosc, 2)) while(Liczba--) m_UmpireModel->AddRow();
    }
    emit WygenerowanoSedziow(true);
}

void CompetitionManager::on_actionStan_triggered(){

}

void CompetitionManager::on_actionRozegraj_Mecze_triggered(){
    if(m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.isEmpty() && m_Zawody->Druzyny()->ListaPrzeciaganieLiny.isEmpty() && m_Zawody->Druzyny()->ListaDwaOgnie.isEmpty()){
        QMessageBox::warning(this, "Błąd", "Brak drużyn!");
        return;
    }
    GenerateMatchScores Dialog;
    if(Dialog.exec()) m_Zawody->RozegrajMecze();

}

void CompetitionManager::on_actionZaplanuj_spotkania_triggered(){
    const ListaSpotkan *L = m_Zawody->Spotkania();
    if(L->ListaSiatkowkaPlazowa.size() > 0 || L->ListaPrzeciaganieLiny.size() > 0 || L->ListaDwaOgnie.size() > 0){
        QMessageBox::warning(this, "Błąd", "Spotkania zostały już zaplanowane!");
        return;
    }
    PlanMatchesDialog Dialog;
    if(Dialog.exec()){
        const ListaDruzyn *L = m_Zawody->Druzyny();
        if(L->ListaSiatkowkaPlazowa.size() == 0 && L->ListaPrzeciaganieLiny.size() == 0 && L->ListaDwaOgnie.size() == 0){
            QMessageBox::warning(this, "Błąd", "Brak drużyn!");
            return;
        }
        if(L->ListaSiatkowkaPlazowa.size() == 1){
            QMessageBox::warning(this, "Błąd", "W siatkówce plażowej jest tylko jedna drużyna!");
            return;
        }
        if(L->ListaPrzeciaganieLiny.size() == 1){
            QMessageBox::warning(this, "Błąd", "W przeciąganiu liny jest tylko jedna drużyna!");
            return;
        }
        if(L->ListaDwaOgnie.size() == 1){
            QMessageBox::warning(this, "Błąd", "W dwóch ogniach jest tylko jedna drużyna!");
            return;
        }

        const ListaSedziow *S = m_Zawody->Sedziowie();
        if(L->ListaSiatkowkaPlazowa.size() > 1 && (S->ListaSiatkowkaPlazowaGlowny.size() < 1 || S->ListaSiatkowkaPlazowaPomocniczy.size() < 2)){
            QMessageBox::warning(this, "Błąd", "Niewystarczająca liczba sędziów w siatkówce plażowej!");
            return;
        }
        if(L->ListaPrzeciaganieLiny.size() > 1 && S->ListaPrzeciaganieLinyGlowny.size() < 1){
            QMessageBox::warning(this, "Błąd", "Niewystarczająca liczba sędziów w przeciąganiu liny!");
            return;
        }
        if(L->ListaDwaOgnie.size() > 1 && S->ListaDwaOgnieGlowny.size() < 1){
            QMessageBox::warning(this, "Błąd", "Niewystarczająca liczba sędziów w dwóch ogniach!");
            return;
        }
        m_Zawody->ZaplanujSpotkania();
        m_MatchModel->Init();
        m_StatusBarEtap->setText(EtapText.arg(m_Zawody->EtapToString()));
    }
}

void CompetitionManager::on_actionEdytuj_druzyne_triggered(){
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
    QList<QString> Druzyny;
    Druzyny.append(m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.keys());
    Druzyny.append(m_Zawody->Druzyny()->ListaPrzeciaganieLiny.keys());
    Druzyny.append(m_Zawody->Druzyny()->ListaDwaOgnie.keys());
    qSort(Druzyny);
    SelectTeamDialog Dialog(Druzyny, this);
    connect(&Dialog, SIGNAL(WybierzDruzyne(QString)), this, SLOT(WybranoDruzyneDoEdycji(QString)));
    Dialog.exec();
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

void CompetitionManager::WybranoDruzyneDoEdycji(QString Nazwa){
    Druzyna D;
    if(m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.count(Nazwa)) D = m_Zawody->Druzyny()->ListaSiatkowkaPlazowa.value(Nazwa);
    if(m_Zawody->Druzyny()->ListaPrzeciaganieLiny.count(Nazwa)) D = m_Zawody->Druzyny()->ListaPrzeciaganieLiny.value(Nazwa);
    if(m_Zawody->Druzyny()->ListaDwaOgnie.count(Nazwa)) D = m_Zawody->Druzyny()->ListaDwaOgnie.value(Nazwa);
    EditTeamDialog Dialog(this, D, Konkurencja(D));
    connect(&Dialog, SIGNAL(Edytuj(Druzyna,Druzyna,int)), this, SLOT(EdytujDruzyne(Druzyna,Druzyna,int)));
    connect(this, SIGNAL(EdytowanoDruzyne(bool)), &Dialog, SLOT(UdaoSiem(bool)));
    Dialog.exec();
}

void CompetitionManager::on_widokDruzyn_doubleClicked(const QModelIndex &index){
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
    QString Nazwa = m_TeamProxyModel->data(m_TeamProxyModel->index(index.row(), 0)).toString();
    WybranoDruzyneDoEdycji(Nazwa);
}

void CompetitionManager::on_widokSedziow_doubleClicked(const QModelIndex &index){
    if(m_Zawody->Etap() != Rejestracja){
        QMessageBox::warning(this, "Błąd", "Rejestracja jest zamknięta!");
        return;
    }
    QString Nazwa = m_UmpireProxyModel->data(m_UmpireProxyModel->index(index.row(), 0)).toString();
    Nazwa += " ";
    Nazwa += m_UmpireProxyModel->data(m_UmpireProxyModel->index(index.row(), 1)).toString();
    WybranoSedziegoDoEdycji(Nazwa);
}

bool CompetitionManager::Zapisz(){
    if(m_NazwaPliku.isEmpty()) if(!ZapiszJako()) return false;
    QFile Plik(m_NazwaPliku);
    Plik.open(QIODevice::WriteOnly);
    QDataStream out(&Plik);
    out<<*m_Zawody;
    Plik.flush();
    Plik.close();
    return true;
}

bool CompetitionManager::ZapiszJako(){
    m_NazwaPliku = QFileDialog::getSaveFileName(this, "Zapisz plik", 0, "Pliki zawodów (*.cm)");
    if(m_NazwaPliku.isEmpty()) return false;
    if(m_NazwaPliku.right(3) != ".cm") m_NazwaPliku += ".cm";
    return true;
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

    delete m_UmpireModel;
    m_UmpireModel = new UmpireModel(m_Zawody->Sedziowie());
    m_UmpireProxyModel->setSourceModel(m_UmpireModel);

    delete m_MatchModel;
    m_MatchModel = new MatchModel(m_Zawody->Spotkania());
    m_MatchProxyModel->setSourceModel(m_MatchModel);

    return true;
}
