#ifndef GENERATEJUGDEDIALOG_H
#define GENERATEJUGDEDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class GenerateJugdeDialog;
}

class GenerateJugdeDialog : public QDialog {
    Q_OBJECT
private:
    int m_Liczba = 0;

public:
    explicit GenerateJugdeDialog(QWidget *parent = 0);
    ~GenerateJugdeDialog();

private slots:
    void on_Ilosc_valueChanged(int arg1);
    int  ObliczWartosc();
    void Sprawdz();

signals:
    void GenerujSedziow(int Ilosc, int Konkurencje);

public slots:
    void UdaoSiem(bool Odpowiedz);

private:
    Ui::GenerateJugdeDialog *ui;
};

#endif // GENERATEJUGDEDIALOG_H
