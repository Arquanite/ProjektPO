#include "zawody.h"

#include <QDebug>

int Zawody::Etap() const {
    return m_Etap;
}

QString Zawody::EtapToString() const{
    switch(m_Etap){
        case Rejestracja: return "Rejestracja";
        case RozgrywkiPodstawowe: return "Rozgrywki podstawowe";
        //case DogrywkiPodstawowe: return "Dogrywki do półfinału";
        case Polfinal: return "Półfinał";
        //case DogrywkiPolfinalowe: return "Dogrywki do finału";
        case Final: return "Finał";
    }
    return QString();
}

Zawody::Zawody(int IleOsobWDruzynie) : m_LiczbaOsob(IleOsobWDruzynie){

}

/*Zawody::Zawody(const Zawody &Z) : m_LiczbaOsob(Z.m_LiczbaOsob){
    m_Etap = Z.m_Etap;
    m_Spotkania = Z.m_Spotkania;
    m_Sedziowie = Z.m_Sedziowie;
    m_Druzyny = Z.m_Druzyny;
    m_Zwyciezcy = Z.m_Zwyciezcy;
    m_LiczbaZwyciezcow = Z.m_LiczbaZwyciezcow;
    m_Zakonczone = Z.m_Zakonczone;
}*/

bool Zawody::ZarejestrujDruzyne(Druzyna NowaDruzyna, int Konkurencja){
    if(m_Etap != Rejestracja) return false;

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
    if(m_Etap != Rejestracja) return false;

    for(SedziaGlowny S : m_Sedziowie.ListaSiatkowkaPlazowaGlowny) if(NowySedzia == S) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy) if(NowySedzia == S) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaPrzeciaganieLinyGlowny) if(NowySedzia == S) return false;
    for(SedziaGlowny S : m_Sedziowie.ListaDwaOgnieGlowny) if(NowySedzia == S) return false;

    if(Konkurencja == 0 && Pomocniczy == false){
        m_Sedziowie.ListaSiatkowkaPlazowaGlowny.insert(NowySedzia.Nazwisko() + " " + NowySedzia.Imie(), NowySedzia);
        return true;
    }
    if(Konkurencja == 0 && Pomocniczy == true){
        m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.insert(NowySedzia.Nazwisko() + " " + NowySedzia.Imie(), NowySedzia);
        return true;
    }
    if(Konkurencja == 1 && Pomocniczy == false){
        m_Sedziowie.ListaPrzeciaganieLinyGlowny.insert(NowySedzia.Nazwisko() + " " + NowySedzia.Imie(), NowySedzia);
        return true;
    }
    if(Konkurencja == 2 && Pomocniczy == false){
        m_Sedziowie.ListaDwaOgnieGlowny.insert(NowySedzia.Nazwisko() + " " + NowySedzia.Imie(), NowySedzia);
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

const ListaDruzyn *Zawody::Zwyciezcy() const{
    return &m_Zwyciezcy;
}

void Zawody::ZaplanujSpotkania(){
    if(m_Etap != Rejestracja) return;
    m_Etap = RozgrywkiPodstawowe;

    m_Spotkania.ListaSiatkowkaPlazowa.clear();
    m_Spotkania.ListaPrzeciaganieLiny.clear();
    m_Spotkania.ListaDwaOgnie.clear();
    
    QList<QString> D, S, SP;
    
    D = m_Druzyny.ListaSiatkowkaPlazowa.keys();
    S = m_Sedziowie.ListaSiatkowkaPlazowaGlowny.keys();
    SP = m_Sedziowie.ListaSiatkowkaPlazowaPomocniczy.keys();
    if(D.size() != 0){
        for(int i=0; i<D.size(); i++){
            for(int j=i+1; j<D.size(); j++){
                QString S1, S2;
                S1 = SP.at(qrand()%SP.size());
                S2 = SP.at(qrand()%SP.size());
                while(S1==S2) S2 = SP.at(qrand()%SP.size());
                m_Spotkania.ListaSiatkowkaPlazowa.append(SiatkowkaPlazowa(D.at(i), D.at(j), S.at(qrand()%S.size()), S1, S2));
                m_LiczbaMeczy++;
            }
        }
    }

    D = m_Druzyny.ListaPrzeciaganieLiny.keys();
    S = m_Sedziowie.ListaPrzeciaganieLinyGlowny.keys();
    if(D.size() != 0){
        for(int i=0; i<D.size(); i++){
            for(int j=i+1; j<D.size(); j++){
                m_Spotkania.ListaPrzeciaganieLiny.append(PrzeciaganieLiny(D.at(i), D.at(j), S.at(qrand()%S.size())));
                m_LiczbaMeczy++;
            }
        }
    }

    D = m_Druzyny.ListaDwaOgnie.keys();
    S = m_Sedziowie.ListaDwaOgnieGlowny.keys();
    if(D.size() != 0){
        int C = m_Druzyny.ListaDwaOgnie.first().Zawodnicy().size();
        for(int i=0; i<D.size(); i++){
            for(int j=i+1; j<D.size(); j++){
                m_Spotkania.ListaDwaOgnie.append(DwaOgnie(D.at(i), D.at(j), S.at(qrand()%S.size()), C));
                m_LiczbaMeczy++;
            }
        }
    }
}

void Zawody::RozegrajMecze(){
    if(m_Etap != RozgrywkiPodstawowe) return;
    for(auto &M : m_Spotkania.ListaSiatkowkaPlazowa){
        //m_Druzyny.ListaSiatkowkaPlazowa[M.Rozegraj()].Wygrana();
        RozegrajMecz(&M);
    }

    for(auto &M : m_Spotkania.ListaPrzeciaganieLiny){
        //m_Druzyny.ListaPrzeciaganieLiny[M.Rozegraj()].Wygrana();
        RozegrajMecz(&M);
    }

    for(auto &M : m_Spotkania.ListaDwaOgnie){
        //m_Druzyny.ListaDwaOgnie[M.Rozegraj()].Wygrana();
        RozegrajMecz(&M);
    }
}

void Zawody::RozegrajMecz(Mecz *M){
    QString Nazwa = M->Rozegraj();

    if(m_Druzyny.ListaSiatkowkaPlazowa.contains(Nazwa)){
        m_Druzyny.ListaSiatkowkaPlazowa[Nazwa].Wygrana();
        m_RozegraneMecze++;
    }
    if(m_Druzyny.ListaPrzeciaganieLiny.contains(Nazwa)){
        m_Druzyny.ListaPrzeciaganieLiny[Nazwa].Wygrana();
        m_RozegraneMecze++;
    }
    if(m_Druzyny.ListaDwaOgnie.contains(Nazwa)){
        m_Druzyny.ListaDwaOgnie[Nazwa].Wygrana();
        m_RozegraneMecze++;
    }

    if(m_RozegraneMecze == m_LiczbaMeczy){
        QList<Druzyna> Druzyny, Zwyciezcy, Dogrywki;

        //Siata
        for(QString Nazwa : m_Druzyny.ListaSiatkowkaPlazowa.keys()) Druzyny.append(m_Druzyny.ListaSiatkowkaPlazowa.value(Nazwa));
        qSort(Druzyny);

        for(Druzyna D : Druzyny){
            if(D.Punkty() > Druzyny.at(4).Punkty()) Zwyciezcy.append(D);
            else break;
        }

        for(Druzyna D : Druzyny){
            if(D.Punkty() == Druzyny.at(3).Punkty()) Dogrywki.append(D);
            if(D.Punkty() < Druzyny.at(3).Punkty()) break;
        }
        if(Dogrywki.size() == 1) Dogrywki.clear();

        for(auto &a : m_Spotkania.ListaSiatkowkaPlazowa){
            for(Druzyna D : Dogrywki){
                if(D.Nazwa() == a.Gospodarz()){
                    for(Druzyna F : Dogrywki){
                        if(F.Nazwa() == a.Gosc()){
                            if(a.PunktyGoscia() > a.PunktyGospodarza()){
                                m_Druzyny.ListaSiatkowkaPlazowa[F.Nazwa()].Wygrana();
                            }
                            else {
                                m_Druzyny.ListaSiatkowkaPlazowa[D.Nazwa()].Wygrana();
                            }
                        }
                    }
                }
            }
        }

        for(Druzyna &D : Dogrywki) D = m_Druzyny.ListaSiatkowkaPlazowa.value(D.Nazwa());
        qSort(Dogrywki);
        if(Dogrywki.size()>0){
            for(Druzyna D : Zwyciezcy){
                for(int i=D.Punkty(); i<= Dogrywki.first().Punkty()+2; i++) m_Druzyny.ListaSiatkowkaPlazowa[D.Nazwa()].Wygrana();
            }
            int P = m_LiczbaZwyciezcow-Zwyciezcy.size();
            for(int i=0; i<P; i++){
                m_Druzyny.ListaSiatkowkaPlazowa[Dogrywki.at(i).Nazwa()].Wygrana();
                Zwyciezcy.append(Dogrywki.at(i));
            }
        }

        for(Druzyna D : Zwyciezcy) m_Zwyciezcy.ListaSiatkowkaPlazowa.insert(D.Nazwa(), D);

        Druzyny.clear();
        Zwyciezcy.clear();
        Dogrywki.clear();

        //Przeciaganie Liny
        for(QString Nazwa : m_Druzyny.ListaPrzeciaganieLiny.keys()) Druzyny.append(m_Druzyny.ListaPrzeciaganieLiny.value(Nazwa));
        qSort(Druzyny);

        for(Druzyna D : Druzyny){
            if(D.Punkty() > Druzyny.at(4).Punkty()) Zwyciezcy.append(D);
            else break;
        }

        for(Druzyna D : Druzyny){
            if(D.Punkty() == Druzyny.at(3).Punkty()) Dogrywki.append(D);
            if(D.Punkty() < Druzyny.at(3).Punkty()) break;
        }
        if(Dogrywki.size() == 1) Dogrywki.clear();

        for(auto &a : m_Spotkania.ListaPrzeciaganieLiny){
            for(Druzyna D : Dogrywki){
                if(D.Nazwa() == a.Gospodarz()){
                    for(Druzyna F : Dogrywki){
                        if(F.Nazwa() == a.Gosc()){
                            if(a.PunktyGoscia() > a.PunktyGospodarza()){
                                m_Druzyny.ListaPrzeciaganieLiny[F.Nazwa()].Wygrana();
                            }
                            else {
                                m_Druzyny.ListaPrzeciaganieLiny[D.Nazwa()].Wygrana();
                            }
                        }
                    }
                }
            }
        }

        for(Druzyna &D : Dogrywki) D = m_Druzyny.ListaPrzeciaganieLiny.value(D.Nazwa());
        qSort(Dogrywki);
        if(Dogrywki.size()>0){
            for(Druzyna D : Zwyciezcy){
                for(int i=D.Punkty(); i<= Dogrywki.first().Punkty()+2; i++) m_Druzyny.ListaPrzeciaganieLiny[D.Nazwa()].Wygrana();
            }
            int P = m_LiczbaZwyciezcow-Zwyciezcy.size();
            for(int i=0; i<P; i++){
                m_Druzyny.ListaPrzeciaganieLiny[Dogrywki.at(i).Nazwa()].Wygrana();
                Zwyciezcy.append(Dogrywki.at(i));
            }
        }

        for(Druzyna D : Zwyciezcy) m_Zwyciezcy.ListaPrzeciaganieLiny.insert(D.Nazwa(), D);

        Druzyny.clear();
        Zwyciezcy.clear();
        Dogrywki.clear();

        //Dwa Ognie
        for(QString Nazwa : m_Druzyny.ListaDwaOgnie.keys()) Druzyny.append(m_Druzyny.ListaDwaOgnie.value(Nazwa));
        qSort(Druzyny);

        for(Druzyna D : Druzyny){
            if(D.Punkty() > Druzyny.at(4).Punkty()) Zwyciezcy.append(D);
            else break;
        }

        for(Druzyna D : Druzyny){
            if(D.Punkty() == Druzyny.at(3).Punkty()) Dogrywki.append(D);
            if(D.Punkty() < Druzyny.at(3).Punkty()) break;
        }
        if(Dogrywki.size() == 1) Dogrywki.clear();

        for(auto &a : m_Spotkania.ListaDwaOgnie){
            for(Druzyna D : Dogrywki){
                if(D.Nazwa() == a.Gospodarz()){
                    for(Druzyna F : Dogrywki){
                        if(F.Nazwa() == a.Gosc()){
                            if(a.PunktyGoscia() > a.PunktyGospodarza()){
                                m_Druzyny.ListaDwaOgnie[F.Nazwa()].Wygrana();
                            }
                            else {
                                m_Druzyny.ListaDwaOgnie[D.Nazwa()].Wygrana();
                            }
                        }
                    }
                }
            }
        }

        for(Druzyna &D : Dogrywki) D = m_Druzyny.ListaDwaOgnie.value(D.Nazwa());
        qSort(Dogrywki);
        if(Dogrywki.size()>0){
            for(Druzyna D : Zwyciezcy){
                for(int i=D.Punkty(); i<= Dogrywki.first().Punkty()+2; i++) m_Druzyny.ListaDwaOgnie[D.Nazwa()].Wygrana();
            }
            int P = m_LiczbaZwyciezcow-Zwyciezcy.size();
            for(int i=0; i<P; i++){
                m_Druzyny.ListaDwaOgnie[Dogrywki.at(i).Nazwa()].Wygrana();
                Zwyciezcy.append(Dogrywki.at(i));
            }
        }
        for(Druzyna D : Zwyciezcy) m_Zwyciezcy.ListaDwaOgnie.insert(D.Nazwa(), D);
    }
}

bool Zawody::GenerujDruzyny(int Ilosc, int Konkurencja){
    if(m_Etap != Rejestracja) return false;
    if(Ilosc < 0 || Konkurencja < 0 || Konkurencja > 2) return false;
    while(Ilosc--){
        while(ZarejestrujDruzyne(m_Generator.GenerujDruzyne(m_LiczbaOsob), Konkurencja) == false);
    }
    return true;
}

bool Zawody::GenerujSedziow(int Ilosc, int Konkurencja, bool Pomocniczy){
    if(m_Etap != Rejestracja) return false;
    if(Ilosc < 0 || Konkurencja < 0 || Konkurencja > 2) return false;
    if(Konkurencja > 0 && Pomocniczy == true) return false;
    while(Ilosc--){
        while(ZarejestrujSedziego(m_Generator.GenerujOsobe(), Konkurencja, Pomocniczy) == false);
    }
    return true;
}

int Zawody::LiczbaOsob() const{
    return m_LiczbaOsob;
}

QDataStream &operator<<(QDataStream &out, const Zawody &Z){
    out<<Z.m_Etap<<Z.m_Spotkania<<Z.m_Sedziowie<<Z.m_Druzyny<<Z.m_Zwyciezcy<<Z.m_LiczbaOsob<<Z.m_LiczbaZwyciezcow<<Z.m_Zakonczone;
    return out;
}

QDataStream &operator>>(QDataStream &in, Zawody &Z){
    in>>Z.m_Etap>>Z.m_Spotkania>>Z.m_Sedziowie>>Z.m_Druzyny>>Z.m_Zwyciezcy>>Z.m_LiczbaOsob>>Z.m_LiczbaZwyciezcow>>Z.m_Zakonczone;
    return in;
}
