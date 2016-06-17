#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QDialog>

namespace Ui {
class ExitDialog;
}

/**
 * @brief Klasa okna "W pliku są niezapisanie zmiany".
 *
 * Przed zamknięciem programu wyświetla komunikat o niezapisanych zmianach w pliku.
 * Umożliwia zapis i wyjście, wyjście bez zapisywania lub anulowanie operacji.
 */
class ExitDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Konstruktor.
     * @param NazwaPliku Nazwa pliku, w którym została zapisana poprzednia wersja zawodów.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit ExitDialog(QString NazwaPliku, QWidget *parent = 0);
    ~ExitDialog(); ///< Desktruktor

public slots:
    void Wyjdz(); ///< Zamyka okno bez zapisywania zmian.
    void Anuluj(); ///< Powraca do programu.
    void Zapisz(); ///< Zapisuje zmiany i zamyka okno.

private:
    Ui::ExitDialog *ui;
};

#endif // EXITDIALOG_H
