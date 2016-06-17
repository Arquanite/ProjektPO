#ifndef GENERATEMATCHSCORES_H
#define GENERATEMATCHSCORES_H

#include <QDialog>

namespace Ui {
class GenerateMatchScores;
}

/**
 * @brief Klasa okna "Wygeneruj wyniki zawodów".
 *
 * Prosi użytkownika o potwierdzenie chęci wylosowania wyników meczy.
 */
class GenerateMatchScores : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Konstruktor.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit GenerateMatchScores(QWidget *parent = 0);
    ~GenerateMatchScores(); ///< Destruktor.

private:
    Ui::GenerateMatchScores *ui;
};

#endif // GENERATEMATCHSCORES_H
