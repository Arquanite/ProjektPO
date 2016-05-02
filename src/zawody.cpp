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
    SedziaGlowny *SG = dynamic_cast<SedziaGlowny*>(&SedziaDoUsuniecia);
    if(SG){
        if(m_Sedziowie.ListaSiatkowkaPlazowaGlowny.removeOne(*SG)) return true;
        if(m_Sedziowie.ListaPrzeciaganieLinyGlowny.removeOne(*SG)) return true;
        if(m_Sedziowie.ListaDwaOgnieGlowny.removeOne(*SG)) return true;
    }

    SedziaPomocniczy *SP = dynamic_cast<SedziaPomocniczy*>(&SedziaDoUsuniecia);
    if(SP) if(m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.removeOne(*SP)) return true;

    return false;
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
    m_Spotkania.ListaSiatkowkaPlazowa.clear();
    m_Spotkania.ListaPrzeciaganieLiny.clear();
    m_Spotkania.ListaDwaOgnie.clear();

    int LiczbaDruzyn, LiczbaSedziow, LiczbaSedziowPomocniczych;

    LiczbaSedziow = m_Sedziowie.ListaSiatkowkaPlazowaGlowny.size();
    LiczbaSedziowPomocniczych = m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.size();
    LiczbaDruzyn = m_Druzyny.ListaSiatkowkaPlazowa.size();
    for(int i=0; i<LiczbaDruzyn; i++){
        Druzyna Gospodarz = m_Druzyny.ListaSiatkowkaPlazowa.at(i);
        for(int j=i; j<LiczbaDruzyn; j++){
            Druzyna Gosc = m_Druzyny.ListaSiatkowkaPlazowa.at(j);
            SedziaGlowny SedziaG = m_Sedziowie.ListaSiatkowkaPlazowaGlowny.at(qrand()%LiczbaSedziow);
            SedziaPomocniczy SedziaP1 = m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.at(qrand()%LiczbaSedziowPomocniczych);
            SedziaPomocniczy SedziaP2 = m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.at(qrand()%LiczbaSedziowPomocniczych);

            SiatkowkaPlazowa SP(Gospodarz, Gosc, SedziaG, SedziaP1, SedziaP2);
            m_Spotkania.ListaSiatkowkaPlazowa.append(SP);
        }
    }

    LiczbaSedziow = m_Sedziowie.ListaPrzeciaganieLinyGlowny.size();
    LiczbaDruzyn = m_Druzyny.ListaPrzeciaganieLiny.size();
    for(int i=0; i<LiczbaDruzyn; i++){
        Druzyna Gospodarz = m_Druzyny.ListaPrzeciaganieLiny.at(i);
        for(int j=i; j<LiczbaDruzyn; j++){
            Druzyna Gosc = m_Druzyny.ListaPrzeciaganieLiny.at(j);
            SedziaGlowny SedziaG = m_Sedziowie.ListaPrzeciaganieLinyGlowny.at(qrand()%LiczbaSedziow);

            PrzeciaganieLiny PL(Gospodarz, Gosc, SedziaG);
            m_Spotkania.ListaPrzeciaganieLiny.append(PL);
        }
    }

    LiczbaSedziow = m_Sedziowie.ListaDwaOgnieGlowny.size();
    LiczbaDruzyn = m_Druzyny.ListaDwaOgnie.size();
    for(int i=0; i<LiczbaDruzyn; i++){
        Druzyna Gospodarz = m_Druzyny.ListaDwaOgnie.at(i);
        for(int j=i; j<LiczbaDruzyn; j++){
            Druzyna Gosc = m_Druzyny.ListaDwaOgnie.at(j);
            SedziaGlowny SedziaG = m_Sedziowie.ListaDwaOgnieGlowny.at(qrand()%LiczbaSedziow);

            DwaOgnie DO(Gospodarz, Gosc, SedziaG);
            m_Spotkania.ListaDwaOgnie.append(DO);
        }
    }
}

void Zawody::RozegrajMecze(){
    for(SiatkowkaPlazowa M : m_Spotkania.ListaSiatkowkaPlazowa) M.Rozegraj();
    for(PrzeciaganieLiny M : m_Spotkania.ListaPrzeciaganieLiny) M.Rozegraj();
    for(DwaOgnie M : m_Spotkania.ListaDwaOgnie) M.Rozegraj();
}

void Zawody::GenerujDruzyny(int Ilosc, int LiczbaOsob){
    while(Ilosc--){
        m_Druzyny.ListaSiatkowkaPlazowa.append(m_Generator.GenerujDruzyne(LiczbaOsob));
        m_Druzyny.ListaPrzeciaganieLiny.append(m_Generator.GenerujDruzyne(LiczbaOsob));
        m_Druzyny.ListaDwaOgnie.append(m_Generator.GenerujDruzyne(LiczbaOsob));
    }
}