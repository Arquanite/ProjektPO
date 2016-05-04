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
    teammodel.cpp \
    exitdialog.cpp \
    betterproxymodel.cpp \
    judgemodel.cpp \
    matchmodel.cpp

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
    teammodel.h \
    exitdialog.h \
    betterproxymodel.h \
    judgemodel.h \
    konkurencja.h \
    matchmodel.h

FORMS    += ui/competitionmanager.ui \
    exitdialog.ui

RESOURCES += res/resources.qrc

DISTFILES +=
