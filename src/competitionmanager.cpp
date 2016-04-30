#include "competitionmanager.h"
#include "ui_competitionmanager.h"

CompetitionManager::CompetitionManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::CompetitionManager) {
    ui->setupUi(this);
}

CompetitionManager::~CompetitionManager()
{
    delete ui;
}
