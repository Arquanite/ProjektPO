#include "addteamdialog.h"
#include "ui_addteamdialog.h"

AddTeamDialog::AddTeamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTeamDialog)
{
    ui->setupUi(this);
}

AddTeamDialog::~AddTeamDialog()
{
    delete ui;
}
