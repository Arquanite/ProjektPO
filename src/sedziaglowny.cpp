#include "sedziaglowny.h"

SedziaGlowny::SedziaGlowny(QString Imie, QString Nazwisko) : Sedzia(Imie, Nazwisko){

}

SedziaGlowny::SedziaGlowny(const Osoba &O) : Sedzia(O){

}
