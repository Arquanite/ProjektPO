#ifndef DELETEUMPIREDIALOG_H
#define DELETEUMPIREDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class DeleteUmpireDialog;
}

/**
 * @brief Klasa okna "Usuń sędziego"
 *
 * Wyświetla okno dialogowe z listą sędziów, użytkownik może wybrać którego chce usunąć.
 *
 */
class DeleteUmpireDialog : public QDialog{
    Q_OBJECT
private:
    QStringListModel *m_JudgeModel;
    int m_Zaznaczenie = -1;

public:
    /**
     * @brief Konstruktor
     * @param NazwySedziow Lista nazw wszystkich sędziów sędziujących w zawodach.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit DeleteUmpireDialog(QList<QString> NazwySedziow, QWidget *parent = 0);
    ~DeleteUmpireDialog(); ///< Destruktor

private slots:
    void ZmianaZaznaczenia(QModelIndex index);

public slots:
    /**
     * @brief Odbiera sygnał o rezultacie wykonania usuwania sędziego.
     *
     * Obiekt rodzica po odebraniu sygnału UsunietoSedziego(QString), a następnie wykonaniu odpowiednich operacji
     * wysyła informacje o powodzeniu. Jeżeli udało się usunąć drużynę wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu usuwania sedziego.
     *
     */
    void UdaoSiem(bool Odpowiedz);

    /**
     * @brief Sprawdza czy użytkownik wybrał sędziego do usunięcia.
     *
     * Jeżeli tego nie zrobił wyświetla ostrzeżenie, w przeciwnym wypadku emituje sygnał Usunsędziego(QString).
     *
     */
    void Sprawdz();

signals:
    /**
     * @brief Sygnał używany by zlecić klasie głównej usunięcie sędziego o podanej nazwie.
     */
    void UsunSedziego(QString);

private:
    Ui::DeleteUmpireDialog *ui;
};

#endif // DELETEUMPIREDIALOG_H
