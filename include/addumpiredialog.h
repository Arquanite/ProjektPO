#ifndef ADDUMPIREDIALOG_H
#define ADDUMPIREDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "sedzia.h"

namespace Ui {
class AddUmpireDialog;
}

/**
 * @brief Klasa okna "Dodaj sędziego"
 *
 * Wyświetla okno dialogowe, które umożliwia dodanie nowego sędziego do zawodów.
 * Wymaga wprowadzenia imienia, nazwiska, typu oraz konkurencji, w której sędzia będzie sędziował.
 */
class AddUmpireDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Konstruktor.
     * @param parent Wkaźnik na obiekt rodzica.
     */
    explicit AddUmpireDialog(QWidget *parent = 0);
    ~AddUmpireDialog(); ///< Desktruktor.

public slots:
    /**
     * @brief Sprawda poprawność wpisanych danych i wysyła informację do obiektu rodzica.
     *
     * Wyświetla ostrzeżenia gdy wpisane dane są niepoprawne, np. nie podano imienia sędziego.
     * Po upewnieniu się, że wszystkie pola zostały wypełnione emituje sygnał DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy).
     *
     */
    void Sprawdz();

    /**
     * @brief Odbiera sygnał o rezultacie wykonania dodawania sędziego.
     *
     * Obiekt rodzica po odebraniu sygnału DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy), a następnie wykonaniu
     * odpowiednich operacji wysyła informacje o powodzeniu. Jeżeli udało się dodać sędziego wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu dodawania sędziego.
     *
     */
    void UdaoSiem(bool Odpowiedz);

signals:
    /**
     * @brief Sygnał używany aby zlecić klasie głównej zarejestrowanie nowego sędziego.
     */
    void DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy);

private:
    Ui::AddUmpireDialog *ui;  ///< Klasa interfejsu.
};

#endif // ADDUMPIREDIALOG_H
