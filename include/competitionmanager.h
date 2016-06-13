#ifndef COMPETITIONMANAGER_H
#define COMPETITIONMANAGER_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDataStream>
#include <QLabel>
#include <QTime>
#include <QFile>

#include "generatematchscores.h"
#include "generatejugdedialog.h"
#include "generateteamsdialog.h"
#include "deletejudgedialog.h"
#include "planmatchesdialog.h"
#include "betterproxymodel.h"
#include "deleteteamdialog.h"
#include "selectteamdialog.h"
#include "addjudgedialog.h"
#include "editteamdialog.h"
#include "addteamdialog.h"
#include "judgemodel.h"
#include "matchmodel.h"
#include "exitdialog.h"
#include "teammodel.h"
#include "zawody.h"
#include "state.h"


namespace Ui {
class CompetitionManager;
}

class CompetitionManager : public QMainWindow {
    Q_OBJECT
private:
    Zawody *m_Zawody;

    TeamModel *m_TeamModel;
    JudgeModel *m_JudgeModel;
    MatchModel *m_MatchModel;

    BetterProxyModel *m_TeamProxyModel;
    BetterProxyModel *m_JudgeProxyModel;
    BetterProxyModel *m_MatchProxyModel;

    QString m_NazwaPliku;
    QString EtapText = "Aktualny etap: %1";
    QLabel* m_StatusBarEtap;

protected:
    void closeEvent(QCloseEvent *event);

public:
    explicit CompetitionManager(QWidget *parent = 0);
    ~CompetitionManager();

    void UtworzZawody();

private slots:
    void on_Wszystkie_clicked(bool checked);
    void on_SiatkowkaPlazowa_clicked(bool checked);
    void on_PrzeciaganieLiny_clicked(bool checked);
    void on_DwaOgnie_clicked(bool checked);

    void on_actionDodaj_druzyne_triggered();
    void on_actionUsun_druzyne_triggered();
    void on_actionEdytuj_druzyne_triggered();

    void on_actionDodaj_sedziego_triggered();
    void on_actionUsun_sedziego_triggered();

    void on_actionWygeneruj_Druzyny_triggered();
    void on_actionWygeneruj_Sedziow_triggered();

    void on_actionStan_triggered();
    void on_actionRozegraj_Mecze_triggered();
    void on_actionZaplanuj_spotkania_triggered();
    void on_widokDruzyn_doubleClicked(const QModelIndex &index);


public slots:
    void DodajDruzyne(Druzyna NowaDruzyna, int Konkurencja);
    void UsunDruzyne(QString Nazwa);
    void EdytujDruzyne(Druzyna StaraDruzyna, Druzyna NowaDruzyna, int Konkurencja);
    void WybranoDruzyneDoEdycji(QString Nazwa);

    void DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy);
    void UsunSedziego(QString Nazwa);

    void GenerujSedziow(int Ilosc, int Konkurencje);
    void GenerujDruzyny(int Ilosc, int Konkurencje);

    int  Konkurencja(Druzyna D);

    bool Zapisz();
    bool ZapiszJako();

    bool Otworz();

signals:
    void UtworzonoDruzyne(bool);
    void UsunietoDruzyne(bool);
    void EdytowanoDruzyne(bool);

    void DodanoSedziego(bool);
    void UsunietoSedziego(bool);

    void WygenerowanoSedziow(bool);
    void WygenerowanoDruzyny(bool);

private:
    Ui::CompetitionManager *ui;
};

#endif // COMPETITIONMANAGER_H
