#ifndef SELECTUMPIREDIALOG_H
#define SELECTUMPIREDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class SelectUmpireDialog;
}

class SelectUmpireDialog : public QDialog{
    Q_OBJECT
private:
    QStringListModel *m_JudgeModel;
    int m_Zaznaczenie = -1;

public:
    explicit SelectUmpireDialog(QList<QString> NazwySedziow, QWidget *parent = 0);
    ~SelectUmpireDialog();

public slots:
    void Sprawdz();
    void ZmianaZaznaczenia(QModelIndex index);

signals:
    void WybierzSedziego(QString);

private:
    Ui::SelectUmpireDialog *ui;
};

#endif // SELECTUMPIREDIALOG_H
