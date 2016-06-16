#ifndef EDITUMPIREDIALOG_H
#define EDITUMPIREDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "sedzia.h"

namespace Ui {
class EditUmpireDialog;
}

class EditUmpireDialog : public QDialog {
    Q_OBJECT
private:
    Sedzia m_Sedzia;
    int m_Konkurencja = 0;
    bool m_Pomocniczy = false;

public:
    explicit EditUmpireDialog(QWidget *parent, Sedzia sedzia, int Konkurencja, bool Pomocniczy = false);
    ~EditUmpireDialog();

public slots:
    void Sprawdz();
    void UdaoSiem(bool Odpowiedz);

signals:
    void EdytujSedziego(Sedzia StarySedzia, Sedzia NowySedzia, int Konkurencja, bool Pomocniczy);

private:
    Ui::EditUmpireDialog *ui;
};

#endif // EDITUMPIREDIALOG_H
