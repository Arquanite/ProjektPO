#ifndef DELETEUMPIREDIALOG_H
#define DELETEUMPIREDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class DeleteUmpireDialog;
}

class DeleteUmpireDialog : public QDialog{
    Q_OBJECT
private:
    QStringListModel *m_JudgeModel;
    int m_Zaznaczenie = -1;

public:
    explicit DeleteUmpireDialog(QList<QString> NazwySedziow, QWidget *parent = 0);
    ~DeleteUmpireDialog();

public slots:
    void UdaoSiem(bool Odpowiedz);
    void Sprawdz();
    void ZmianaZaznaczenia(QModelIndex index);

signals:
    void UsunSedziego(QString);

private:
    Ui::DeleteUmpireDialog *ui;
};

#endif // DELETEUMPIREDIALOG_H
