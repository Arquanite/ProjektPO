#ifndef PLANMATCHESDIALOG_H
#define PLANMATCHESDIALOG_H

#include <QDialog>

namespace Ui {
class PlanMatchesDialog;
}

/**
 * @brief Klasa okna "Zaplanuj spotkania"
 *
 * Wyświetla okno dialogowe z prośbą o potwierdzenie chęci automatycznego zestawienia spotkań
 * między wszystkimi drużynami biorącymi udział w zawodach.
 */
class PlanMatchesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlanMatchesDialog(QWidget *parent = 0); ///< Kostruktor.
    ~PlanMatchesDialog(); ///< Destruktor.

private:
    Ui::PlanMatchesDialog *ui;
};

#endif // PLANMATCHESDIALOG_H
