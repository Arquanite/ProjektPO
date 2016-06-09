#ifndef PLANMATCHESDIALOG_H
#define PLANMATCHESDIALOG_H

#include <QDialog>

namespace Ui {
class PlanMatchesDialog;
}

class PlanMatchesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlanMatchesDialog(QWidget *parent = 0);
    ~PlanMatchesDialog();

private:
    Ui::PlanMatchesDialog *ui;
};

#endif // PLANMATCHESDIALOG_H
