#ifndef GENERATEUMPIREDIALOG_H
#define GENERATEUMPIREDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class GenerateUmpireDialog;
}

/**
 * @brief Klasa okna "Wygeneruj sędziów".
 *
 * Wyświetla okno dialogowe, umożliwiające użytkownikowi wygenerowanie wybranej przez niego ilości
 * sędziów w każdej zaznaczonej przez niego dyscyplinie.
 */
class GenerateUmpireDialog : public QDialog {
    Q_OBJECT
private:
    int m_Liczba = 0;

public:
    /**
     * @brief Konstruktor.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit GenerateUmpireDialog(QWidget *parent = 0);
    ~GenerateUmpireDialog(); ///< Destruktor

private slots:
    void on_Ilosc_valueChanged(int arg1);
    int  ObliczWartosc();
    void Sprawdz();

signals:
    /**
     * @brief Sygnał używany aby zlecić klasie głównej generowanie sędziów.
     * @param Ilosc Ilość sędziów, która zostanie wygenerowana dla KAŻDEJ zaznaczonej konkurencji.
     * @param Konkurencje Konkurencje, w których mają zostać wygenerowani sędziowie.
     */
    void GenerujSedziow(int Ilosc, int Konkurencje);

public slots:
    /**
     * @brief Odbiera sygnał o rezultacie generowania sędziów.
     *
     * Obiekt rodzica po odebraniu sygnału GenerujSedziow(int Ilosc, int Konkurencje), a następnie wykonaniu
     * odpowiednich operacji wysyła informacje o powodzeniu. Jeżeli udało się wygenerować sędziów
     * wysyłane jest true, w przeciwnym wypadku false.
     *
     * Jeżeli Odpowiedz = false, zostaje wyświetlony komunikat o błędzie.
     * W przeciwnym wypadku okno jest zamykane.
     *
     * @param Odpowiedz Informacja o powodzeniu generowania sędziów.
     *
     */
    void UdaoSiem(bool Odpowiedz);

private:
    Ui::GenerateUmpireDialog *ui;
};

#endif // GENERATEUMPIREDIALOG_H
