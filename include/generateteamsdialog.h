#ifndef GENERATETEAMSDIALOG_H
#define GENERATETEAMSDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class GenerateTeamsDialog;
}

class GenerateTeamsDialog : public QDialog {
    Q_OBJECT
private:
    int m_Liczba = 0;

public:
    explicit GenerateTeamsDialog(QWidget *parent = 0);
    ~GenerateTeamsDialog();

private slots:
    void on_Ilosc_valueChanged(int arg1);
    int  ObliczWartosc();
    void Sprawdz();

signals:
    void GenerujDruzyny(int Ilosc, int Konkurencje);

public slots:
    void UdaoSiem(bool Odpowiedz);

private:
    Ui::GenerateTeamsDialog *ui;
};

#endif // GENERATETEAMSDIALOG_H
