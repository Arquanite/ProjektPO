#ifndef COMPETITIONMANAGER_H
#define COMPETITIONMANAGER_H

#include <QMainWindow>

namespace Ui {
class CompetitionManager;
}

class CompetitionManager : public QMainWindow {
    Q_OBJECT

public:
    explicit CompetitionManager(QWidget *parent = 0);
    ~CompetitionManager();

private:
    Ui::CompetitionManager *ui;
};

#endif // COMPETITIONMANAGER_H
