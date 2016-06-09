#ifndef DELETEJUDGEDIALOG_H
#define DELETEJUDGEDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class DeleteJudgeDialog;
}

class DeleteJudgeDialog : public QDialog{
    Q_OBJECT
private:
    QStringListModel *m_JudgeModel;
    int m_Zaznaczenie = -1;

public:
    explicit DeleteJudgeDialog(QList<QString> NazwySedziow, QWidget *parent = 0);
    ~DeleteJudgeDialog();

public slots:
    void UdaoSiem(bool Odpowiedz);
    void Sprawdz();
    void ZmianaZaznaczenia(QModelIndex index);

signals:
    void UsunSedziego(QString);

private:
    Ui::DeleteJudgeDialog *ui;
};

#endif // DELETEJUDGEDIALOG_H
