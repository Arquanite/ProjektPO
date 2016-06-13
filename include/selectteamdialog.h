#ifndef SELECTTEAMDIALOG_H
#define SELECTTEAMDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class SelectTeamDialog;
}

class SelectTeamDialog : public QDialog{
    Q_OBJECT
private:
    QStringListModel *m_TeamModel;
    int m_Zaznaczenie = -1;

public:
    explicit SelectTeamDialog(QList<QString> NazwyDruzyn, QWidget *parent = 0);
    ~SelectTeamDialog();

public slots:
    void Sprawdz();
    void ZmianaZaznaczenia(QModelIndex index);

signals:
    void WybierzDruzyne(QString);

private:
    Ui::SelectTeamDialog *ui;
};

#endif // SELECTTEAMDIALOG_H
