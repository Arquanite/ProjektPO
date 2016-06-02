#ifndef ADDTEAMDIALOG_H
#define ADDTEAMDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "druzyna.h"

namespace Ui {
class AddTeamDialog;
}

class AddTeamDialog : public QDialog {
    Q_OBJECT
private:
    int m_LiczbaZawodnikow = 0;
    int m_Konkurencja = 0;
    Druzyna m_Druzyna;

public:
    explicit AddTeamDialog(QWidget *parent, int LiczbaZawodnikow);
    ~AddTeamDialog();

public slots:
    void UdaoSiem(bool Odpowiedz);
    void Sprawdz();

signals:
    void Dodaj(Druzyna NowaDruzyna, int Konkurencja);

private:
    Ui::AddTeamDialog *ui;
};

#endif // ADDTEAMDIALOG_H
