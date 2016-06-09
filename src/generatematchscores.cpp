#include "generatematchscores.h"
#include "ui_generatematchscores.h"

GenerateMatchScores::GenerateMatchScores(QWidget *parent) : QDialog(parent), ui(new Ui::GenerateMatchScores){
    ui->setupUi(this);
    connect(ui->Tak, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui->Nie, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

GenerateMatchScores::~GenerateMatchScores()
{
    delete ui;
}
