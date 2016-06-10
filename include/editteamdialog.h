#ifndef EDITTEAMDIALOG_H
#define EDITTEAMDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "druzyna.h"

namespace Ui {
class EditTeamDialog;
}

class EditTeamDialog : public QDialog {
    Q_OBJECT
private:
    int m_LiczbaZawodnikow = 0;
    int m_Konkurencja = 0;
    Druzyna m_Druzyna;

public:
    explicit EditTeamDialog(QWidget *parent, Druzyna druzyna, int Konkurencja);
    ~EditTeamDialog();

public slots:
    void UdaoSiem(bool Odpowiedz);
    void Sprawdz();

signals:
    void Edytuj(Druzyna StaraDruzyna, Druzyna NowaDruzyna, int Konkurencja);

private:
    Ui::EditTeamDialog *ui;
};

#endif // EDITTEAMDIALOG_H
