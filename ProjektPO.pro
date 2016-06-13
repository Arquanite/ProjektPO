#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T20:27:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjektPO
TEMPLATE = app

INCLUDEPATH += include/

SOURCES += src/main.cpp\
    src/competitionmanager.cpp \
    src/osoba.cpp \
    src/sedzia.cpp \
    src/zawodnik.cpp \
    src/sedziapomocniczy.cpp \
    src/sedziaglowny.cpp \
    src/druzyna.cpp \
    src/mecz.cpp \
    src/meczindywidualny.cpp \
    src/meczdruzynowy.cpp \
    src/przeciaganieliny.cpp \
    src/pilka.cpp \
    src/dwaognie.cpp \
    src/siatkowka.cpp \
    src/siatkowkaplazowa.cpp \
    src/listaspotkan.cpp \
    src/listasedziow.cpp \
    src/listadruzyn.cpp \
    src/zawody.cpp \
    src/generator.cpp \
    src/teammodel.cpp \
    src/exitdialog.cpp \
    src/betterproxymodel.cpp \
    src/judgemodel.cpp \
    src/matchmodel.cpp \
    src/addteamdialog.cpp \
    src/deleteteamdialog.cpp \
    src/addjudgedialog.cpp \
    src/deletejudgedialog.cpp \
    src/generateteamsdialog.cpp \
    src/generatejugdedialog.cpp \
    src/state.cpp \
    src/generatematchscores.cpp \
    src/planmatchesdialog.cpp \
    src/editteamdialog.cpp \
    include/selectteamdialog.cpp

HEADERS  += include/competitionmanager.h \
    include/osoba.h \
    include/sedzia.h \
    include/zawodnik.h \
    include/sedziapomocniczy.h \
    include/sedziaglowny.h \
    include/druzyna.h \
    include/mecz.h \
    include/meczindywidualny.h \
    include/meczdruzynowy.h \
    include/przeciaganieliny.h \
    include/pilka.h \
    include/dwaognie.h \
    include/siatkowka.h \
    include/siatkowkaplazowa.h \
    include/listaspotkan.h \
    include/listasedziow.h \
    include/listadruzyn.h \
    include/zawody.h \
    include/generator.h \
    include/teammodel.h \
    include/exitdialog.h \
    include/betterproxymodel.h \
    include/judgemodel.h \
    include/konkurencja.h \
    include/matchmodel.h \
    include/addteamdialog.h \
    include/deleteteamdialog.h \
    include/addjudgedialog.h \
    include/deletejudgedialog.h \
    include/generateteamsdialog.h \
    include/generatejugdedialog.h \
    include/state.h \
    include/generatematchscores.h \
    include/planmatchesdialog.h \
    include/editteamdialog.h \
    include/selectteamdialog.h

FORMS    += ui/competitionmanager.ui \
    ui/exitdialog.ui \
    ui/addteamdialog.ui \
    ui/deleteteamdialog.ui \
    ui/addjudgedialog.ui \
    ui/deletejudgedialog.ui \
    ui/generateteamsdialog.ui \
    ui/generatejugdedialog.ui \
    ui/state.ui \
    ui/generatematchscores.ui \
    ui/planmatchesdialog.ui \
    ui/editteamdialog.ui \
    include/selectteamdialog.ui

RESOURCES += res/resources.qrc

DISTFILES +=
