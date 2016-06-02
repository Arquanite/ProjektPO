#ifndef DELETETEAMDIALOG_H
#define DELETETEAMDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class DeleteTeamDialog;
}

class DeleteTeamDialog : public QDialog {
    Q_OBJECT
private:
    QStringListModel *m_TeamModel;
    int m_Zaznaczenie = -1;

public:
    explicit DeleteTeamDialog(QList<QString> NazwyDruzyn, QWidget *parent = 0);
    ~DeleteTeamDialog();

public slots:
    void UdaoSiem(bool Odpowiedz);
    void Sprawdz();
    void ZmianaZaznaczenia(QModelIndex index);

signals:
    void UsunDruzyne(QString);

private:
    Ui::DeleteTeamDialog *ui;
};

#endif // DELETETEAMDIALOG_H
