#include "zawodnik.h"

Zawodnik::Zawodnik(QString Imie, QString Nazwisko) : Osoba(Imie, Nazwisko){

}

Zawodnik::Zawodnik(const Osoba &O) : Osoba(O){

}
