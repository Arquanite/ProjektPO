#include "sedziapomocniczy.h"

SedziaPomocniczy::SedziaPomocniczy(QString Imie, QString Nazwisko) : Sedzia(Imie, Nazwisko){

}

SedziaPomocniczy::SedziaPomocniczy(const Osoba &O) : Sedzia(O){

}

SedziaPomocniczy::SedziaPomocniczy(){

}
