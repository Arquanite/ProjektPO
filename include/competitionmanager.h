#ifndef COMPETITIONMANAGER_H
#define COMPETITIONMANAGER_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDataStream>
#include <QLabel>
#include <QTime>
#include <QFile>

#include "generatematchscores.h"
#include "generateumpiredialog.h"
#include "generateteamsdialog.h"
#include "selectumpiredialog.h"
#include "deleteumpiredialog.h"
#include "planmatchesdialog.h"
#include "betterproxymodel.h"
#include "deleteteamdialog.h"
#include "editumpiredialog.h"
#include "selectteamdialog.h"
#include "addumpiredialog.h"
#include "editteamdialog.h"
#include "addteamdialog.h"
#include "aboutdialog.h"
#include "umpiremodel.h"
#include "matchmodel.h"
#include "exitdialog.h"
#include "teammodel.h"
#include "zawody.h"


namespace Ui {
class CompetitionManager;
}

/**
 * @brief Klasa główna programu.
 *
 * Klasa CompetitionManager jest klasą główną programu, jej zadania obejmują m.in. zarządzanie
 * zawodami, wyświetlanie okna głównego, wywoływania okien dialogowych oraz odbieranie i reagowanie na ich sygnały.
 */
class CompetitionManager : public QMainWindow {
    Q_OBJECT
private:
    Zawody *m_Zawody;
    Zawody *m_Polfinal;
    Zawody *m_Final;

    TeamModel *m_TeamModel;
    UmpireModel *m_UmpireModel;
    MatchModel *m_MatchModel;
    MatchModel *m_HalfFinalModel;
    MatchModel *m_FinalModel;

    BetterProxyModel *m_TeamProxyModel;
    BetterProxyModel *m_UmpireProxyModel;
    BetterProxyModel *m_MatchProxyModel;
    BetterProxyModel *m_HalfFinalProxyModel;
    BetterProxyModel *m_FinalProxyModel;

    QString m_NazwaPliku;
    QString EtapText = "Aktualny etap: %1";
    QLabel* m_StatusBarEtap;

protected:
    /**
     * @brief Przechwytuje zdarzenie zamknięcia programu, proponuje użytkownikowi zapisanie zmian.
     *
     * Kiedy użytkownik naciście przycisk "x" na pasku tytułu okno nie zostanie od razu zamknięte.
     * Wyświetli się okno dialogowe klasy ExitDialog z zapytaniem o potwierdzenie nawigacji i zapisanie zmian.
     *
     * @param event Zdarzenie zamknięcia.
     */
    void closeEvent(QCloseEvent *event);

public:
    /**
     * @brief Konstruktor
     * @param parent Wskaźnik na obiekt rodzica;
     */
    explicit CompetitionManager(QWidget *parent = 0);
    ~CompetitionManager(); ///< Destruktor.

    void UtworzZawody(); ///< Tworzy nowe zawody.

private slots:
    void on_Wszystkie_clicked(bool checked);
    void on_SiatkowkaPlazowa_clicked(bool checked);

    void on_PrzeciaganieLiny_clicked(bool checked);
    void on_DwaOgnie_clicked(bool checked);

    void on_actionDodaj_druzyne_triggered();
    void on_actionUsun_druzyne_triggered();
    void on_actionEdytuj_druzyne_triggered();

    void on_actionDodaj_sedziego_triggered();
    void on_actionUsun_sedziego_triggered();
    void on_actionEdytuj_dane_sedziego_triggered();

    void on_actionWygeneruj_Druzyny_triggered();
    void on_actionWygeneruj_Sedziow_triggered();

    void on_actionStan_triggered();
    void on_actionRozegraj_Mecze_triggered();
    void on_actionZaplanuj_spotkania_triggered();

    void on_widokDruzyn_doubleClicked(const QModelIndex &index);
    void on_widokSedziow_doubleClicked(const QModelIndex &index);

    void on_actionO_programie_triggered();
    void on_actionNowy_triggered();

public slots:
    /**
     * @brief Dodaje nową drużynę do zawodów.
     *
     * Emituje sygnał UtworzonoDruzyne(bool).
     *
     * @param NowaDruzyna Drużyna, którą chcemy dodać.
     * @param Konkurencja Konkurencja w jakiej będzie uczestniczyć.
     */
    void DodajDruzyne(Druzyna NowaDruzyna, int Konkurencja);

    /**
     * @brief Usuwa drużynę o podanej nazwie.
     *
     * Emituje sygnał UsunietoDruzyne(bool).
     *
     * @param Nazwa Nazwa drużyny, którą chcemy usunąć.
     */
    void UsunDruzyne(QString Nazwa);

    /**
     * @brief Zastąpia starą drużyne nową. Przypisuje do określonej konkurencji.
     *
     * Emituje sygnał EdytowanoDruzyne(bool).
     *
     * @param StaraDruzyna Drużyna, którą chcemy zastąpić.
     * @param NowaDruzyna Zmieniona wersja drużyny, która zostanie dodana.
     * @param Konkurencja Konkurencja, w której NowaDruzyna będzie uczestniczyć.
     */
    void EdytujDruzyne(Druzyna StaraDruzyna, Druzyna NowaDruzyna, int Konkurencja);


    /**
     * @brief Dodaje nowego sędziego do zawodów.
     *
     * Emituje sygnał DodanoSedziego(bool).
     *
     * @param NowySedzia Sędzia, którego chcemy dodać do zawodów.
     * @param Konkurencja Konkurencja, w której będzie sędziował.
     * @param Pomocniczy Typ sędziego, true oznacza, że nie jest to sędzia główny lecz pomocniczy.
     */
    void DodajSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy);

    /**
     * @brief Usuwa sędziego o podanej nazwie.
     *
     * Emituje sygnał UsunietoSedziego(bool).
     *
     * @param Nazwa Identyfikator sędziego powstały w z połączenia jego nazwiska i imienia.
     */
    void UsunSedziego(QString Nazwa);

    /**
     * @brief Zastąpia starego sędziego nowym. Przypisuje do określonej konkurencji.
     *
     * Emituje sygnał EdytowanoSedziego(bool).
     *
     * @param StarySedzia Sędzia, którego chcemy zastąpić.
     * @param NowySedzia Zmieniona wersja sędziego, który zostanie dodany.
     * @param Konkurencja Konkurencja, w której będzie sędziował.
     * @param Pomocniczy Typ sędziego, true oznacza, że nie będzie to sędzia główny lecz pomocniczy.
     */
    void EdytujSedziego(Sedzia StarySedzia, Sedzia NowySedzia, int Konkurencja, bool Pomocniczy = false);

    /**
     * @brief Generuje sędziów.
     *
     * Generuje określoną parametrem liczbę sędziów, w KAŻDEJ z konkurencji.
     *
     * Konkurencje są określone na zasadzie flag bitowych:
     *
     * -Siatkówka plażowa główny - 1
     *
     * -Siatkówka plażowa pomocniczy - 2
     *
     * -Przeciąganie liny - 4
     *
     * -Dwa ognie - 8
     *
     * Emituje sygnał WygenerowanoSedziow(bool);
     *
     * @param Ilosc Ilość sędziów do wygenerowania w KAŻDEJ z konkurencji.
     * @param Konkurencje Konkurencje do jakich zostaną dodani sędziowie.
     */
    void GenerujSedziow(int Ilosc, int Konkurencje);

    /**
     * @brief Generuje drużyny.
     *
     * Generuje określoną parametrem liczbę drużyn, w KAŻDEJ z konkurencji.
     *
     * Konkurencje są określone na zasadzie flag bitowych:
     *
     * -Siatkówka plażowa - 1
     *
     * -Przeciąganie liny - 2
     *
     * -Dwa ognie - 4
     *
     * Emituje sygnał WygenerowanoDruzyny(bool);
     *
     * @param Ilosc Ilość druzyn do wygenerowania w KAŻDEJ z konkurencji.
     * @param Konkurencje Konkurencje do jakich zostaną dodane drużyny.
     */
    void GenerujDruzyny(int Ilosc, int Konkurencje);

    /**
     * @brief Zwraca konkurencję, w której rywalizuje dana drużyna.
     * @param D Drużyna, którą chcemy sprawdzić.
     * @return 0-Siatkówka plażowa, 1-Przeciaganie liny, 2-Dwa ognie.
     */
    int  Konkurencja(Druzyna D);

    /**
     * @brief Zapisuje zawody do pliku.
     *
     * Jeżeli nazwa pliku nie została wcześniej określona wywołuje ZapiszJako().
     *
     * @return true w przypadku udanego zapisu, w przeciwnym wypadku false.
     */
    bool Zapisz();

    /**
     * @brief Otwiera okno dialogowe z wyborem miejsca i nazwy dla zapisywanego pliku.
     * @return true w przypadku udanego zapisu, w przeciwnym wypadku false.
     */
    bool ZapiszJako();

    /**
     * @brief Wyświetla okno wyboru pliku, a następnie otwiera plik.
     * @return true w przypadku udanego odczytu, w przeciwnym wypadku false.
     */
    bool Otworz();

private:
    void WybranoDruzyneDoEdycji(QString Nazwa);
    void WybranoSedziegoDoEdycji(QString Nazwa);

signals:
    void UtworzonoDruzyne(bool); ///< Powiadamia o powodzeniu tworzenia drużyny.
    void UsunietoDruzyne(bool); ///< Powiadamia o powodzeniu usuwania drużyny.
    void EdytowanoDruzyne(bool); ///< Powiadamia o powodzeniu edycji drużyny.

    void DodanoSedziego(bool); ///< Powiadamia o powodzeniu dodawania sędziego.
    void UsunietoSedziego(bool); ///< Powiadamia o powodzeniu usuwania sędziego.
    void EdytowanoSedziego(bool); ///< Powiadamia o powodzeniu edycji sędziego.

    void WygenerowanoSedziow(bool); ///< Powiadamia o powodzeniu generowania sędziów.
    void WygenerowanoDruzyny(bool); ///< Powiadamia o powodzeniu generowania drużyn.

private:
    Ui::CompetitionManager *ui;
};

#endif // COMPETITIONMANAGER_H
