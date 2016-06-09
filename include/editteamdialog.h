#ifndef EDITTEAMDIALOG_H
#define EDITTEAMDIALOG_H

#include <QDialog>

namespace Ui {
class EditTeamDialog;
}

class EditTeamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditTeamDialog(QWidget *parent = 0);
    ~EditTeamDialog();

private:
    Ui::EditTeamDialog *ui;
};

#endif // EDITTEAMDIALOG_H
