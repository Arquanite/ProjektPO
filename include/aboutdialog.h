#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

/**
 * @brief Klasa okna "O programie"
 *
 * Wyświetla okno dialogowe "O programie", w którym znajdują się podstawowe informacje o programie i autorze.
 */
class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     * @param parent Wskaźnik na rodzica okna.
     */
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog(); ///< Destruktor.

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
