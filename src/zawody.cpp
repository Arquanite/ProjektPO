#include "zawody.h"

#include <QDebug>

bool Zawody::ZarejestrujDruzyne(Druzyna NowaDruzyna, int Konkurencja){

    for(Druzyna D : m_Druzyny.ListaSiatkowkaPlazowa) if(NowaDruzyna.Nazwa() == D.Nazwa()) return false;
    for(Druzyna D : m_Druzyny.ListaPrzeciaganieLiny) if(NowaDruzyna.Nazwa() == D.Nazwa()) return false;
    for(Druzyna D : m_Druzyny.ListaDwaOgnie) if(NowaDruzyna.Nazwa() == D.Nazwa()) return false;

    if(Konkurencja == 0){
        m_Druzyny.ListaSiatkowkaPlazowa.insert(NowaDruzyna.Nazwa(), NowaDruzyna);
        return true;
    }

    if(Konkurencja == 1){
        m_Druzyny.ListaPrzeciaganieLiny.insert(NowaDruzyna.Nazwa(), NowaDruzyna);
        return true;
    }

    if(Konkurencja == 2){
        m_Druzyny.ListaDwaOgnie.insert(NowaDruzyna.Nazwa(), NowaDruzyna);
        return true;
    }

    return false;
}

bool Zawody::ZarejestrujSedziego(Sedzia NowySedzia, int Konkurencja, bool Pomocniczy){
    for(SedziaGlowny S : m_Sedziowie.ListaSiatkowkaPlazowaGlowny) if(NowySedzia == S) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy) if(NowySedzia == S) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaPrzeciaganieLinyGlowny) if(NowySedzia == S) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaDwaOgnieGlowny) if(NowySedzia == S) return false;

    if(Konkurencja == 0 && Pomocniczy == false){
        m_Sedziowie.ListaSiatkowkaPlazowaGlowny.insert(NowySedzia.Imie()+NowySedzia.Nazwisko(), NowySedzia);
        return true;
    }
    if(Konkurencja == 0 && Pomocniczy == true){
        m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.insert(NowySedzia.Imie()+NowySedzia.Nazwisko(), NowySedzia);
        return true;
    }
    if(Konkurencja == 1 && Pomocniczy == false){
        m_Sedziowie.ListaPrzeciaganieLinyGlowny.insert(NowySedzia.Imie()+NowySedzia.Nazwisko(), NowySedzia);
        return true;
    }
    if(Konkurencja == 2 && Pomocniczy == false){
        m_Sedziowie.ListaDwaOgnieGlowny.insert(NowySedzia.Imie()+NowySedzia.Nazwisko(), NowySedzia);
        return true;
    }

    return false;
}

bool Zawody::UsunDruzyne(QString DruzynaDoUsuniecia){
    if(m_Druzyny.ListaSiatkowkaPlazowa.remove(DruzynaDoUsuniecia)) return true;
    if(m_Druzyny.ListaPrzeciaganieLiny.remove(DruzynaDoUsuniecia)) return true;
    if(m_Druzyny.ListaDwaOgnie.remove(DruzynaDoUsuniecia)) return true;
    return false;
}

bool Zawody::UsunSedziego(QString SedziaDoUsuniecia){
    if(m_Sedziowie.ListaSiatkowkaPlazowaGlowny.remove(SedziaDoUsuniecia)) return true;
    if(m_Sedziowie.ListaPrzeciaganieLinyGlowny.remove(SedziaDoUsuniecia)) return true;
    if(m_Sedziowie.ListaDwaOgnieGlowny.remove(SedziaDoUsuniecia)) return true;
    if(m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.remove(SedziaDoUsuniecia)) return true;
    return false;
}

const ListaSedziow *Zawody::Sedziowie() const {
    return &m_Sedziowie;
}

const ListaDruzyn *Zawody::Druzyny() const {
    return &m_Druzyny;
}

const ListaSpotkan *Zawody::Spotkania() const {
    return &m_Spotkania;
}

const ListaDruzyn *Zawody::Zwyciezcy() const {
    return &m_Zwyciezcy;
}

void Zawody::ZaplanujSpotkania(){
    m_Spotkania.ListaSiatkowkaPlazowa.clear();
    m_Spotkania.ListaPrzeciaganieLiny.clear();
    m_Spotkania.ListaDwaOgnie.clear();
    //! TODO Planowanie spotkań
}

void Zawody::RozegrajMecze(){
    for(auto &A : m_Druzyny.ListaDwaOgnie){
        qDebug()<<A.Nazwa();
    }
    //! TODO Rozgrywanie meczy
}

void Zawody::GenerujDruzyny(int Ilosc, int LiczbaOsob){
    while(Ilosc--){
        ZarejestrujDruzyne(m_Generator.GenerujDruzyne(LiczbaOsob), 0);
        ZarejestrujDruzyne(m_Generator.GenerujDruzyne(LiczbaOsob), 1);
        ZarejestrujDruzyne(m_Generator.GenerujDruzyne(LiczbaOsob), 2);
    }
}

void Zawody::GenerujSedziow(int Ilosc){
    while(Ilosc--){
        while(ZarejestrujSedziego(m_Generator.GenerujOsobe(), 0) == false);
        while(ZarejestrujSedziego(m_Generator.GenerujOsobe(), 0, true) == false);
        while(ZarejestrujSedziego(m_Generator.GenerujOsobe(), 1) == false);
        while(ZarejestrujSedziego(m_Generator.GenerujOsobe(), 2) == false);
    }
}
