#ifndef BETTERPROXYMODEL_H
#define BETTERPROXYMODEL_H

#include <QSortFilterProxyModel>

/**
 * @brief BetterProxyModel jest ulepszeniem klasy QSortFilterProxyModel.
 *
 * Klasa QSortFilterProxyModel jest sortująco-filtrującym modelem pośredniczącym umożliwiającym łatwe
 * sortowanie i filtrowanie danych w widokach. Jest to bardzo przydatne gdy chcemy np. wyświetlić tylko
 * drużyny siatkówki, albo posortować je od najlepszej do najsłabszej.
 *
 * Wprowadzona tu poprawka obejmuje metodę headerData(int section, Qt::Orientation orientation, int role) const.
 * Pierwotnie indeksy wierszy były do nich na stałe przyporządkowane. Z tego powodu przy wykonaniu sortowania lub
 * filtrowania numery traciły swoją kolejność i niemożliwe było ich uporządkowanie. W klasie BetterProxyModel
 * indeksy nie są przypisane do wierszy, zawsze zaczynają się 1 i numerują kolejne wiersze. Dzięki temu można
 * łatwo stwierdzić np. na którym miejscu dana drużyna się znajduje lub ilu sędziów zarejestrowano.
 *
 */
class BetterProxyModel : public QSortFilterProxyModel
{
public:
    BetterProxyModel(); ///< Konstruktor.

    /**
     * @brief Zarządza wyświetlaniem danych nagłówków.
     * @param section Numer sekcji.
     * @param orientation Orientacja, może być pozioma lub pionowa.
     * @param role Rola, więcej na ten temat można poczytać w dokumentacji Qt.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // BETTERPROXYMODEL_H
