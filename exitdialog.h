#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QDialog>

namespace Ui {
class ExitDialog;
}

class ExitDialog : public QDialog {
    Q_OBJECT

public:
    explicit ExitDialog(QString NazwaPliku, QWidget *parent = 0);
    ~ExitDialog();

public slots:
    void Wyjdz();
    void Anuluj();
    void Zapisz();

private:
    Ui::ExitDialog *ui;
};

#endif // EXITDIALOG_H
