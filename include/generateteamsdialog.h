#ifndef GENERATETEAMSDIALOG_H
#define GENERATETEAMSDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class GenerateTeamsDialog;
}

/**
 * @brief Klasa okna "Wygeneruj drużyny".
 *
 * Wyświetla okno dialogowe, umożliwiające użytkownikowi wygenerowanie wybranej przez niego ilości
 * drużyn w każdej zaznaczonej przez niego dyscyplinie.
 */
class GenerateTeamsDialog : public QDialog {
    Q_OBJECT
private:
    int m_Liczba = 0;

public:
    /**
     * @brief Konstruktor.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit GenerateTeamsDialog(QWidget *parent = 0);
    ~GenerateTeamsDialog(); ///< Destruktor

private slots:
    void on_Ilosc_valueChanged(int arg1);
    int  ObliczWartosc();
    void Sprawdz();

signals:
    /**
     * @brief Sygnał używany aby zlecić klasie głównej generowanie drużyn.
     * @param Ilosc Ilość drużyn, która zostanie wygenerowana dla KAŻDEJ zaznaczonej konkurencji.
     * @param Konkurencje Konkurencje, w których mają zostać wygenerowane drużyny.
     */
    void GenerujDruzyny(int Ilosc, int Konkurencje);

public slots:
    /**
     * @brief Odbiera sygnał o rezultacie generowania drużyn.
     *
     * Obiekt rodzica po odebraniu sygnału GenerujDruzyny(int Ilosc, int Konkurencje), a następnie wykonaniu
     * odpowiednich operacji wysyła informacje o powodzeniu. Jeżeli udało się wygenerować drużyny
     * wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu generowania drużyn.
     *
     */
    void UdaoSiem(bool Odpowiedz);

private:
    Ui::GenerateTeamsDialog *ui;
};

#endif // GENERATETEAMSDIALOG_H
