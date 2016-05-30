#ifndef ADDTEAMDIALOG_H
#define ADDTEAMDIALOG_H

#include <QDialog>

namespace Ui {
class AddTeamDialog;
}

class AddTeamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTeamDialog(QWidget *parent = 0);
    ~AddTeamDialog();

private:
    Ui::AddTeamDialog *ui;
};

#endif // ADDTEAMDIALOG_H
