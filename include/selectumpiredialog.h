#ifndef SELECTUMPIREDIALOG_H
#define SELECTUMPIREDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class SelectUmpireDialog;
}

/**
 * @brief Klasa okna "Wybierz sędziego do edycji"
 *
 * Okno wyświetlane jest gdy użytkownik wybierze opcję edycji sędziego.
 * Wyświetla listę wszystkich sędziów sędziujących w zawodach posortowaną
 * alfabetycznie.
 */
class SelectUmpireDialog : public QDialog{
    Q_OBJECT
private:
    QStringListModel *m_JudgeModel;
    int m_Zaznaczenie = -1;

private slots:
    void ZmianaZaznaczenia(QModelIndex index);

public:
    /**
     * @brief Konstruktor.
     * @param NazwyDruzyn Lista wszystkich sędziów sędziujących w zawodach.
     * @param parent Wskaźnik na obiekt rodzica.
     */
    explicit SelectUmpireDialog(QList<QString> NazwySedziow, QWidget *parent = 0);
    ~SelectUmpireDialog(); ///< Destruktor.

public slots:
    /**
     * @brief Sprawdza czy użytkownik wybrał sędziego do edycji.
     *
     * Jeżeli tego nie zrobił wyświetla ostrzeżenie, w przeciwnym wypadku emituje sygnał WybierzSedziego(QString).
     *
     */
    void Sprawdz();

signals:
    void WybierzSedziego(QString); ///< Sygnał używany aby przekazać klasie głównej nazwę sędziego, którego użytkownik chce edytować.

private:
    Ui::SelectUmpireDialog *ui;
};

#endif // SELECTUMPIREDIALOG_H
