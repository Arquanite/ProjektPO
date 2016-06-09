#include "planmatchesdialog.h"
#include "ui_planmatchesdialog.h"

PlanMatchesDialog::PlanMatchesDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PlanMatchesDialog){
    ui->setupUi(this);
    connect(ui->Tak, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui->Nie, SIGNAL(clicked(bool)), this, SLOT(reject()));
}

PlanMatchesDialog::~PlanMatchesDialog()
{
    delete ui;
}
