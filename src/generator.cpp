#include "generator.h"

Generator::Generator(){
    QFile *plik;
    QTextStream *in;

    plik = new QFile(":/osoby/imiona_m");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()) ImionaM.append(in->readLine());
    delete in;
    plik->close();
    delete plik;

    plik = new QFile(":/osoby/imiona_z");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()) ImionaZ.append(in->readLine());
    delete in;
    plik->close();
    delete plik;

    plik = new QFile(":/osoby/nazwiska_m");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()) NazwiskaM.append(in->readLine());
    delete in;
    plik->close();
    delete plik;

    plik = new QFile(":/osoby/nazwiska_z");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()) NazwiskaZ.append(in->readLine());
    delete in;
    plik->close();
    delete plik;

    plik = new QFile(":/drużyny/przymiotniki");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()) Przymiotniki.append(in->readLine());
    delete in;
    plik->close();
    delete plik;

    plik = new QFile(":/drużyny/rzeczowniki");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()) Rzeczowniki.append(in->readLine());
    delete in;
    plik->close();
    delete plik;

    plik = new QFile(":/drużyny/te_trzecie");
    plik->open(QIODevice::ReadOnly);
    in = new QTextStream(plik);
    while(!in->atEnd()) TeTrzecie.append(in->readLine());
    delete in;
    plik->close();
    delete plik;
}

Osoba Generator::GenerujKobiete(){
    return Osoba(ImionaZ.at(qrand()%ImionaZ.size()), NazwiskaZ.at(qrand()%NazwiskaZ.size()));
}

Osoba Generator::GenerujMezczyzne(){
    return Osoba(ImionaM.at(qrand()%ImionaM.size()), NazwiskaM.at(qrand()%NazwiskaM.size()));
}

Osoba Generator::GenerujOsobe(){
    return (qrand()%2 ? GenerujKobiete() : GenerujMezczyzne());
}

QString Generator::GenerujNazwe(){
    QString Przymiotnik = Przymiotniki.at(qrand()%Przymiotniki.size());
    QString Rzeczownik = Rzeczowniki.at(qrand()%Rzeczowniki.size());
    QString TenTrzeci = TeTrzecie.at(qrand()%TeTrzecie.size());

    if(Rzeczownik.at(Rzeczownik.size()-1) == 'a') Przymiotnik.append('a');
    else if(Rzeczownik.at(Rzeczownik.size()-1) == 'o') Przymiotnik.append('e');
    else Przymiotnik.append('y');

    return Przymiotnik + " " + Rzeczownik + " " + TenTrzeci;
}

Druzyna Generator::GenerujDruzyne(int LiczbaOsob){
    QList<Zawodnik> Zawodnicy;
    while(LiczbaOsob--){
        Zawodnicy.append(GenerujOsobe());
    }
    return Druzyna(GenerujNazwe(), Zawodnicy);
}
