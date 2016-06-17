#ifndef EDITUMPIREDIALOG_H
#define EDITUMPIREDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "sedzia.h"

namespace Ui {
class EditUmpireDialog;
}

/**
 * @brief Klasa okna "Edytuj sędziego"
 *
 * Wyświetla okno dialogowe, które umożliwia edytowanie istniejącego sędziego.
 */
class EditUmpireDialog : public QDialog {
    Q_OBJECT
private:
    Sedzia m_Sedzia;
    int m_Konkurencja = 0;
    bool m_Pomocniczy = false;

public:
    /**
     * @brief Konstruktor
     * @param parent Wskaźnik na rodzica okna.
     * @param sedzia Sędzia, którego chcemy edytować.
     * @param Konkurencja Konkurencja, w której sędziuje.
     * @param Pomocniczy Typ sędziego.
     */
    explicit EditUmpireDialog(QWidget *parent, Sedzia sedzia, int Konkurencja, bool Pomocniczy = false);
    ~EditUmpireDialog(); ///< Destruktor

public slots:
    /**
     * @brief Odbiera sygnał o rezultacie edycji sędziego.
     *
     * Obiekt rodzica po odebraniu sygnału EdytujSedziego(Sedzia StarySedzia, Sedzia NowySedzia, int Konkurencja, bool Pomocniczy),
     * a następnie wykonaniu odpowiednich operacji wysyła informacje o powodzeniu. Jeżeli udało się edytować
     * sędziego wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu edycji sędziego.
     *
     */
    void Sprawdz();

    /**
     * @brief Sprawda poprawność wpisanych danych i wysyła informację do obiektu rodzica.
     *
     * Wyświetla ostrzeżenia gdy wpisane dane są niepoprawne, np. nie podano imienia sędziego.
     * Po upewnieniu się, że wszystkie pola zostały wypełnione emituje sygnał
     * EdytujSedziego(Sedzia StarySedzia, Sedzia NowySedzia, int Konkurencja, bool Pomocniczy).
     *
     */
    void UdaoSiem(bool Odpowiedz);

signals:
    /**
     * @brief Sygnał używany aby zlecić klasie głównej edycje sędziego.
     * @param StarySedzia Sędzia, którego chcemy zastąpić.
     * @param NowySedzia Sędzia z wprowadzonymi zmianami.
     * @param Konkurencja Konkurencja, w której będzie sędziował.
     * @param Pomocniczy Typ sędziego
     */
    void EdytujSedziego(Sedzia StarySedzia, Sedzia NowySedzia, int Konkurencja, bool Pomocniczy);

private:
    Ui::EditUmpireDialog *ui;
};

#endif // EDITUMPIREDIALOG_H
