#ifndef EDITTEAMDIALOG_H
#define EDITTEAMDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "druzyna.h"

namespace Ui {
class EditTeamDialog;
}

/**
 * @brief Klasa okna "Edytuj drużynę"
 *
 * Wyświetla okno dialogowe, które umożliwia edytowanie istniejącej drużyny.
 */
class EditTeamDialog : public QDialog {
    Q_OBJECT
private:
    int m_LiczbaZawodnikow = 0;
    int m_Konkurencja = 0;
    Druzyna m_Druzyna;

public:
    /**
     * @brief Konstruktor
     * @param parent Wskaźnik na rodzica okna.
     * @param druzyna Drużyna, którą chcemy edytować.
     * @param Konkurencja Konkurencja, w której uczestniczy.
     */
    explicit EditTeamDialog(QWidget *parent, Druzyna druzyna, int Konkurencja);
    ~EditTeamDialog(); ///< Destruktor

public slots:
    /**
     * @brief Odbiera sygnał o rezultacie edycji drużyny.
     *
     * Obiekt rodzica po odebraniu sygnału Edytuj(Druzyna StaraDruzyna, Druzyna NowaDruzyna, int Konkurencja),
     * a następnie wykonaniu odpowiednich operacji wysyła informacje o powodzeniu. Jeżeli udało się edytować
     * drużynę wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu edycji drużyny.
     *
     */
    void UdaoSiem(bool Odpowiedz);

    /**
     * @brief Sprawda poprawność wpisanych danych i wysyła informację do obiektu rodzica.
     *
     * Wyświetla ostrzeżenia gdy wpisane dane są niepoprawne, np. nie podano nazwy drużyny.
     * Po upewnieniu się, że wszystkie pola zostały wypełnione emituje sygnał Edytuj(Druzyna StaraDruzyna, Druzyna NowaDruzyna, int Konkurencja).
     *
     */
    void Sprawdz();

signals:
    /**
     * @brief Sygnał używany aby zlecić klasie głównej edycje drużyny.
     * @param StaraDruzyna Drużyna, którą chcemy zastąpić.
     * @param NowaDruzyna Drużyna z wprowadzonymi zmianami.
     * @param Konkurencja Konkurencja, w której nowa drużyna będzie startować.
     */
    void Edytuj(Druzyna StaraDruzyna, Druzyna NowaDruzyna, int Konkurencja);

private:
    Ui::EditTeamDialog *ui;
};

#endif // EDITTEAMDIALOG_H
