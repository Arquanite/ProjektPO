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
    src/matchmodel.cpp \
    src/addteamdialog.cpp \
    src/deleteteamdialog.cpp \
    src/generateteamsdialog.cpp \
    src/generatematchscores.cpp \
    src/planmatchesdialog.cpp \
    src/editteamdialog.cpp \
    src/selectteamdialog.cpp \
    src/editumpiredialog.cpp \
    src/selectumpiredialog.cpp \
    src/addumpiredialog.cpp \
    src/deleteumpiredialog.cpp \
    src/generateumpiredialog.cpp \
    src/umpiremodel.cpp \
    src/aboutdialog.cpp

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
    include/matchmodel.h \
    include/addteamdialog.h \
    include/deleteteamdialog.h \
    include/generateteamsdialog.h \
    include/generatematchscores.h \
    include/planmatchesdialog.h \
    include/editteamdialog.h \
    include/selectteamdialog.h \
    include/editumpiredialog.h \
    include/selectumpiredialog.h \
    include/addumpiredialog.h \
    include/deleteumpiredialog.h \
    include/generateumpiredialog.h \
    include/umpiremodel.h \
    include/aboutdialog.h

FORMS    += ui/competitionmanager.ui \
    ui/exitdialog.ui \
    ui/addteamdialog.ui \
    ui/deleteteamdialog.ui \
    ui/generateteamsdialog.ui \
    ui/generatematchscores.ui \
    ui/planmatchesdialog.ui \
    ui/editteamdialog.ui \
    ui/selectteamdialog.ui \
    ui/editumpiredialog.ui \
    ui/selectumpiredialog.ui \
    ui/addumpiredialog.ui \
    ui/deleteumpiredialog.ui \
    ui/generateumpiredialog.ui \
    ui/aboutdialog.ui

RESOURCES += res/resources.qrc

DISTFILES +=
