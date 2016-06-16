#ifndef ADDUMPIREDIALOG_H
#define ADDUMPIREDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "sedzia.h"

namespace Ui {
class AddUmpireDialog;
}

class AddUmpireDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddUmpireDialog(QWidget *parent = 0);
    ~AddUmpireDialog();

public slots:
    void Sprawdz();
    void UdaoSiem(bool Odpowiedz);

signals:
    void DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy);

private:
    Ui::AddUmpireDialog *ui;
};

#endif // ADDUMPIREDIALOG_H
