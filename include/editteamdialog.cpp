#include "editteamdialog.h"
#include "ui_editteamdialog.h"

EditTeamDialog::EditTeamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTeamDialog)
{
    ui->setupUi(this);
}

EditTeamDialog::~EditTeamDialog()
{
    delete ui;
}
