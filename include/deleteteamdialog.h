#ifndef DELETETEAMDIALOG_H
#define DELETETEAMDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class DeleteTeamDialog;
}

/**
 * @brief Klasa okna "Usuń drużynę"
 *
 * Wyświetla okno dialogowe z listą drużyn, użytkownik może wybrać którą chce usunąć.
 *
 */
class DeleteTeamDialog : public QDialog {
    Q_OBJECT
private:
    QStringListModel *m_TeamModel;
    int m_Zaznaczenie = -1;

public:
    /**
     * @brief Konstruktor.
     * @param NazwyDruzyn Lista nazw wszystkich drużyn biorących udział w zawodach.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit DeleteTeamDialog(QList<QString> NazwyDruzyn, QWidget *parent = 0);
    ~DeleteTeamDialog(); ///< Destruktor

private slots:
    void ZmianaZaznaczenia(QModelIndex index);

public slots:
    /**
     * @brief Odbiera sygnał o rezultacie wykonania usuwania drużyny.
     *
     * Obiekt rodzica po odebraniu sygnału UsunietoDruzyne(QString), a następnie wykonaniu odpowiednich operacji
     * wysyła informacje o powodzeniu. Jeżeli udało się usunąć drużynę wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu usuwania drużyny.
     *
     */
    void UdaoSiem(bool Odpowiedz);

    /**
     * @brief Sprawdza czy użytkownik wybrał drużynę do usunięcia.
     *
     * Jeżeli tego nie zrobił wyświetla ostrzeżenie, w przeciwnym wypadku emituje sygnał UsunDruzyne(QString).
     *
     */
    void Sprawdz();

signals:
    /**
     * @brief Sygnał używany by zlecić klasie głównej usunięcie drużyny o podanej nazwie.
     */
    void UsunDruzyne(QString);

private:
    Ui::DeleteTeamDialog *ui;
};

#endif // DELETETEAMDIALOG_H
