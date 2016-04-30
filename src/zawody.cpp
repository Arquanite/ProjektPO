#include "zawody.h"

bool Zawody::ZarejestrujDruzyne(Druzyna NowaDruzyna, int Konkurencja){

    for(Druzyna D : m_Druzyny.ListaSiatkowkaPlazowa) if(NowaDruzyna.Nazwa() == D.Nazwa()) return false;
    for(Druzyna D : m_Druzyny.ListaPrzeciaganieLiny) if(NowaDruzyna.Nazwa() == D.Nazwa()) return false;
    for(Druzyna D : m_Druzyny.ListaDwaOgnie) if(NowaDruzyna.Nazwa() == D.Nazwa()) return false;

    if(Konkurencja == 0){
        m_Druzyny.ListaSiatkowkaPlazowa.append(NowaDruzyna);
        return true;
    }

    if(Konkurencja == 1){
        m_Druzyny.ListaPrzeciaganieLiny.append(NowaDruzyna);
        return true;
    }

    if(Konkurencja == 2){
        m_Druzyny.ListaDwaOgnie.append(NowaDruzyna);
        return true;
    }

    return false;
}

bool Zawody::ZarejestrujSedziegoGlownego(SedziaGlowny NowySedzia, int Konkurencja){
    for(SedziaGlowny S : m_Sedziowie.ListaSiatkowkaPlazowaGlowny) if(NowySedzia.Imie() == S.Imie() && NowySedzia.Nazwisko() == S.Nazwisko()) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaPrzeciaganieLinyGlowny) if(NowySedzia.Imie() == S.Imie() && NowySedzia.Nazwisko() == S.Nazwisko()) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaDwaOgnieGlowny) if(NowySedzia.Imie() == S.Imie() && NowySedzia.Nazwisko() == S.Nazwisko()) return false;

    if(Konkurencja == 0){
        m_Sedziowie.ListaSiatkowkaPlazowaGlowny.append(NowySedzia);
        return true;
    }
    if(Konkurencja == 1){
        m_Sedziowie.ListaPrzeciaganieLinyGlowny.append(NowySedzia);
        return true;
    }
    if(Konkurencja == 2){
        m_Sedziowie.ListaDwaOgnieGlowny.append(NowySedzia);
        return true;
    }

    return false;
}

bool Zawody::UsunDruzyne(Druzyna DruzynaDoUsuniecia){
    if(m_Druzyny.ListaSiatkowkaPlazowa.removeOne(DruzynaDoUsuniecia)) return true;
    if(m_Druzyny.ListaPrzeciaganieLiny.removeOne(DruzynaDoUsuniecia)) return true;
    if(m_Druzyny.ListaDwaOgnie.removeOne(DruzynaDoUsuniecia)) return true;
    return false;
}

bool Zawody::UsunSedziego(Sedzia SedziaDoUsuniecia){
    if(SedziaDoUsuniecia.Imie() == "lol") return true;
    return true;
}

ListaSedziow Zawody::Sedziowie() const {
    return m_Sedziowie;
}

ListaDruzyn Zawody::Druzyny() const {
    return m_Druzyny;
}

ListaSpotkan Zawody::Spotkania() const {
    return m_Spotkania;
}
ListaDruzyn Zawody::Zwyciezcy() const {
    return m_Zwyciezcy;
}

void Zawody::ZaplanujSpotkania(){

}

void Zawody::RozegrajMecze(){

}
