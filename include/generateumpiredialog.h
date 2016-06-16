#ifndef GENERATEUMPIREDIALOG_H
#define GENERATEUMPIREDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class GenerateUmpireDialog;
}

class GenerateUmpireDialog : public QDialog {
    Q_OBJECT
private:
    int m_Liczba = 0;

public:
    explicit GenerateUmpireDialog(QWidget *parent = 0);
    ~GenerateUmpireDialog();

private slots:
    void on_Ilosc_valueChanged(int arg1);
    int  ObliczWartosc();
    void Sprawdz();

signals:
    void GenerujSedziow(int Ilosc, int Konkurencje);

public slots:
    void UdaoSiem(bool Odpowiedz);

private:
    Ui::GenerateUmpireDialog *ui;
};

#endif // GENERATEUMPIREDIALOG_H
