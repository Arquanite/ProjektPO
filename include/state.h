#ifndef STATE_H
#define STATE_H

#include <QDialog>

namespace Ui {
class State;
}

class State : public QDialog
{
    Q_OBJECT

public:
    explicit State(QWidget *parent = 0);
    ~State();

private:
    Ui::State *ui;
};

#endif // STATE_H
