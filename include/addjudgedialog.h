#ifndef ADDJUDGEDIALOG_H
#define ADDJUDGEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "sedzia.h"

namespace Ui {
class AddJudgeDialog;
}

class AddJudgeDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddJudgeDialog(QWidget *parent = 0);
    ~AddJudgeDialog();

public slots:
    void Sprawdz();
    void UdaoSiem(bool Odpowiedz);

signals:
    void DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy);

private:
    Ui::AddJudgeDialog *ui;
};

#endif // ADDJUDGEDIALOG_H
