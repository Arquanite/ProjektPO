#ifndef COMPETITIONMANAGER_H
#define COMPETITIONMANAGER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>

#include "betterproxymodel.h"
#include "judgemodel.h"
#include "matchmodel.h"
#include "teammodel.h"

#include "exitdialog.h"

#include "zawody.h"

#include <QDebug>

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

public slots:
    void DodajDruzyne(Druzyna NowaDruzyna, int Konkurencja);

signals:
    void UtworzonoDruzyne(bool);

private:
    Ui::CompetitionManager *ui;
};

#endif // COMPETITIONMANAGER_H
