#ifndef ADDTEAMDIALOG_H
#define ADDTEAMDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "druzyna.h"

namespace Ui {
class AddTeamDialog;
}

/**
 * @brief Klasa okna "Dodaj drużynę"
 *
 * Wyświetla okno dialogowe, które umożliwia dodanie nowej drużyny do zawodów.
 * Wymaga wprowadzenia nazwy, danych zawodników oraz konkurencji, w której drużyna będzie brać udział.
 */
class AddTeamDialog : public QDialog {
    Q_OBJECT
private:
    int m_LiczbaZawodnikow = 0;
    int m_Konkurencja = 0;
    Druzyna m_Druzyna;

public:
    /**
     * @brief Konstruktor
     * @param parent Wskaźnik na rodzica okna.
     * @param LiczbaZawodnikow Liczba zawodników w drużynie.
     */
    explicit AddTeamDialog(QWidget *parent, int LiczbaZawodnikow);
    ~AddTeamDialog(); ///< Destruktor.

public slots:
    /**
     * @brief Odbiera sygnał o rezultacie wykonania dodawania drużyny.
     *
     * Obiekt rodzica po odebraniu sygnału Dodaj(Druzyna NowaDruzyna, int Konkurencja), a następnie wykonaniu odpowiednich operacji
     * wysyła informacje o powodzeniu. Jeżeli udało się dodać drużynę wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu dodawania drużyny.
     *
     */
    void UdaoSiem(bool Odpowiedz);

    /**
     * @brief Sprawda poprawność wpisanych danych i wysyła informację do obiektu rodzica.
     *
     * Wyświetla ostrzeżenia gdy wpisane dane są niepoprawne, np. nie podano nazwy drużyny.
     * Po upewnieniu się, że wszystkie pola zostały wypełnione emituje sygnał Dodaj(Druzyna NowaDruzyna, int Konkurencja).
     *
     */
    void Sprawdz();

signals:
    /**
     * @brief Sygnał używany aby zlecić klasie głównej zarejestrowanie nowej drużyny.
     * @param NowaDruzyna Obiekt drużyny, która ma zostać dodana do zawodów.
     * @param Konkurencja
     */
    void Dodaj(Druzyna NowaDruzyna, int Konkurencja);

private:
    Ui::AddTeamDialog *ui;
};

#endif // ADDTEAMDIALOG_H
