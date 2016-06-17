#ifndef SELECTTEAMDIALOG_H
#define SELECTTEAMDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class SelectTeamDialog;
}
/**
 * @brief Klasa okna "Wybierz drużynę do edycji"
 *
 * Okno wyświetlane jest gdy użytkownik wybierze opcję edycji drużyny.
 * Wyświetla listę wszystkich drużyn biorących udział w zawodach posortowaną
 * alfabetycznie.
 */
class SelectTeamDialog : public QDialog{
    Q_OBJECT
private:
    QStringListModel *m_TeamModel;
    int m_Zaznaczenie = -1;

public:
    /**
     * @brief Konstruktor.
     * @param NazwyDruzyn Lista wszystkich drużyn biorących udział w zawodach.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit SelectTeamDialog(QList<QString> NazwyDruzyn, QWidget *parent = 0);
    ~SelectTeamDialog(); ///< Destruktor.

private slots:
    void ZmianaZaznaczenia(QModelIndex index);

public slots:
    /**
     * @brief Sprawdza czy użytkownik wybrał drużynę do edycji.
     *
     * Jeżeli tego nie zrobił wyświetla ostrzeżenie, w przeciwnym wypadku emituje sygnał WybierzDruzyne(QString).
     *
     */
    void Sprawdz();

signals:
    void WybierzDruzyne(QString); ///< Sygnał używany aby przekazać klasie głównej nazwę drużyny, którą użytkownik chce edytować.

private:
    Ui::SelectTeamDialog *ui;
};

#endif // SELECTTEAMDIALOG_H
