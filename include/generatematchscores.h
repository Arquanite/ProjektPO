#ifndef GENERATEMATCHSCORES_H
#define GENERATEMATCHSCORES_H

#include <QDialog>

namespace Ui {
class GenerateMatchScores;
}

class GenerateMatchScores : public QDialog {
    Q_OBJECT

public:
    explicit GenerateMatchScores(QWidget *parent = 0);
    ~GenerateMatchScores();

private:
    Ui::GenerateMatchScores *ui;
};

#endif // GENERATEMATCHSCORES_H
