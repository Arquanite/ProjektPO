#include "competitionmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CompetitionManager w;
    w.show();

    return a.exec();
}
