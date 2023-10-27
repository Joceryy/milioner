#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Struktura pytan i odpowiedzi
struct Pytanie
{
    string pytanie;
    vector<string> opcje;
    int poprawna_odpowiedź;
};

// Klasa jak ma wyglądać gra milionerzy
class Milionerzy
{
private:
    vector<Pytanie> pytania;
    int aktualne_pytanie;
    int wygrana;
    bool osiagnieto_gwarantowana_wygrana = false;
    int wygrana_gwarantowana = 0; // Zmienna do gwarantowanej wygranej
    vector<int> pulaNagrod;

public:
    Milionerzy()
    {
        aktualne_pytanie = 0;
        wygrana = 0;
        srand(time(0));

        // Pytania, odpowiedzi i wygrane
        Pytanie q1;
        q1.pytanie = "Ktory gaz stanowi wiekszosc atmosfery Ziemi?";
        q1.opcje = { "Azot", "Tlen", "Argon", "Wodor" };
        q1.poprawna_odpowiedź = 0;

        Pytanie q2;
        q2.pytanie = "Jaka jest stolica Francji?";
        q2.opcje = { "Londyn", "Berlin", "Paryz", "Madryt" };
        q2.poprawna_odpowiedź = 2;

        Pytanie q3;
        q3.pytanie = "Gdzie Slazaczki nosza laczki?";
        q3.opcje = { "na glowie", "na rekach", "na plecach", "na nogach" };
        q3.poprawna_odpowiedź = 3;

        Pytanie q4;
        q4.pytanie = "Ile kosztuje chleb, ktory pierwotnie kosztowal 10 zl, nastepnie potanial do 8 zl, a pozniej jego cena wzrosla o 20 proc.?";
        q4.opcje = { "8,20zl", "9zl", "9,60zl", "10zl" };
        q4.poprawna_odpowiedź = 2;

        Pytanie q5;
        q5.pytanie = "Co jest prawda o podkarpackim miescie, ktore ma w nazwie urzadzenie wlokiennicze?";
        q5.opcje = { "slynie z hut szkla", "w X wieku bylo stolica Polski", "ma milion mieszkancow", "ma w herbie lodz" };
        q5.poprawna_odpowiedź = 0;

        Pytanie q6;
        q6.pytanie = "Kojot wyglada jak cos pomiedzy...";
        q6.opcje = { "kuna a lasica", "bobrem a wiewiorka", "rysiem a zbikiem", "wilkiem a szakalem" };
        q6.poprawna_odpowiedź = 3;

        Pytanie q7;
        q7.pytanie = "Kto w marcu 2023 r. w meczu z Albania w trakcie eliminacji do Euro strzelil zwycieskiego gola dla Polski?";
        q7.opcje = { "Jan Bednarek", "Piotr Zielinski", "Robert Lewandowski", "Karol Swiderski" };
        q7.poprawna_odpowiedź = 3;

        Pytanie q8;
        q8.pytanie = "W lore ligi legend, Jarvan III zginal z reki";
        q8.opcje = { "Siona", "Katariny", "Naafiri", "Swaina" };
        q8.poprawna_odpowiedź = 1;

        Pytanie q9;
        q9.pytanie = "Bedzie pasterka i...";
        q9.opcje = { "msza swieta", "koniec postu", "koledy sie zaspiewa", "bede rzygal do wiaderka" };
        q9.poprawna_odpowiedź = 3;

        Pytanie q10;
        q10.pytanie = "Ktory to legendarny angielski pirat?";
        q10.opcje = { "Sinobrody", "Czarnobrody", "Bialobrody", "Krzywousty" };
        q10.poprawna_odpowiedź = 1;

        Pytanie q11;
        q11.pytanie = "O co chodzi we frazeologizmie: cos jest warte lub niewarte zachodu?";
        q11.opcje = { "O kierunek geograficzny", "O mekke dla Polakow za PRL_u", "O czasownik zabieganie", "O czasownik wybieganie" };
        q11.poprawna_odpowiedź = 2;

        Pytanie q12;
        q12.pytanie = "Zzuc, a nawet zezuc, to...";
        q12.opcje = { "Pociotek baka", "przezuty tyton", "zdjac buty z nog", "spogladac ukradkiem" };
        q12.poprawna_odpowiedź = 2;

        Pytanie q13;
        q13.pytanie = "Ile odcinkow prostych znajdziemy w rzymskiej cyfrze 50?";
        q13.opcje = { "4", "3", "2", "1" };
        q13.poprawna_odpowiedź = 2;

        Pytanie q14;
        q14.pytanie = "Kto jest mistrzem tego samego oreza, w jakim specjalizowala sie mitologiczna Artemida?";
        q14.opcje = { "Zorro", "Legolas", "Don Kichot", "Longinus Podbipieta" };
        q14.poprawna_odpowiedź = 1;

        Pytanie q15;
        q15.pytanie = "Most nad Sundem laczy:";
        q15.opcje = { "Norwegie z Dania", "Danie ze Szwecja", "Szwecje z Finlandia", "Finlandie z Estonia" };
        q15.poprawna_odpowiedź = 1;

        Pytanie q16;
        q16.pytanie = "Ten, ktory byl dwa razy krolem Polski, od 1725 r. byl takze?";
        q16.opcje = { "Tesciem krola Francji", "Zieciem krola Wegier", "Szwagrem cara Bulagarii", "Ojcem krola Polski" };
        q16.poprawna_odpowiedź = 0;

        Pytanie q17;
        q17.pytanie = "W Polsce jest najmniej miast na litere: ";
        q17.opcje = { "A", "B", "C", "D" };
        q17.poprawna_odpowiedź = 0;

        Pytanie q18;
        q18.pytanie = "Co sie dzieje kiedy konfederacja ma wysokie poparcie?";
        q18.opcje = { "Lewica szerzy propagande", "PiS szerzy propagande", "Memcen sie cieszy", "Pojawia sie Janusz Korwin-Mikke caly na bialo" };
        q18.poprawna_odpowiedź = 3 ;

        Pytanie q19;
        q19.pytanie = "Ktora pora roku to po wlosku, hiszpansku i portugalsku primavera?";
        q19.opcje = { "Zima", "Lato", "Jesien", "Wiosna" };
        q19.poprawna_odpowiedź = 3;

        Pytanie q20;
        q20.pytanie = "Ktore panstwo w 1932 roku wyslalo uzbrojonych w karabiny maszynowe zolnierzy do walki z ptakami emu?";
        q20.opcje = { "Nowa Zelandia", "Brazylia", "Chiny", "Australia" };
        q20.poprawna_odpowiedź = 3;

        pytania.push_back(q1);
        pytania.push_back(q2);
        pytania.push_back(q3);
        pytania.push_back(q4);
        pytania.push_back(q5);
        pytania.push_back(q6);
        pytania.push_back(q7);
        pytania.push_back(q8);
        pytania.push_back(q9);
        pytania.push_back(q10);
        pytania.push_back(q11);
        pytania.push_back(q12);
        pytania.push_back(q13);
        pytania.push_back(q13);
        pytania.push_back(q14);
        pytania.push_back(q15);
        pytania.push_back(q16);
        pytania.push_back(q17);
        pytania.push_back(q18);
        pytania.push_back(q19);
        pytania.push_back(q20);

        // Poziomy wygranych
        pulaNagrod = { 500, 1000, 2000, 5000, 10000, 20000, 40000, 75000, 125000, 250000, 500000, 1000000 };

        // Mieszanie pytań
        srand(time(0));
        random_shuffle(pytania.begin(), pytania.end());
    }

    void wyświetl_pytanie()
    {
        cout << "Pytanie " << aktualne_pytanie + 1 << ": " << pytania[aktualne_pytanie].pytanie << endl;
        for (int i = 0; i < pytania[aktualne_pytanie].opcje.size(); i++)
        {
            cout << i + 1 << ". " << pytania[aktualne_pytanie].opcje[i] << endl;
        }
    }

    //sprawdza odpowiedź
    bool czy_odpowiedź_poprawna(int odpowiedź)
    {
        return odpowiedź == pytania[aktualne_pytanie].poprawna_odpowiedź + 1;
    }

    void mechanika()
    {
        int ilosc_udzielonych_odpowiedzi = 0; // Sprawdza ile udzielono odpowiedzi

        while (aktualne_pytanie < pytania.size())
        {
            wyświetl_pytanie();
            int odpowiedź;
            cout << "Wybierz odpowiez (1-4) lub 0, aby odejsc ze swoja wygrana: ";
            cin >> odpowiedź;

            if (odpowiedź == 0)
            {
                cout << "Odszedles z wygranymi " << wygrana << " zl. Gratulacje!" << endl; // Wyświetla wygraną
                break;
            }

            if (czy_odpowiedź_poprawna(odpowiedź))
            {
                wygrana = pulaNagrod[aktualne_pytanie];
                if (wygrana == 1000 || wygrana == 40000)
                {
                    osiagnieto_gwarantowana_wygrana = true;
                    wygrana_gwarantowana = wygrana; // aktualizuje gwarantowaną wygraną
                }
                cout << "Poprawna odpowiedz! Obecnie posiadasz " << wygrana << " zl!" << endl;
            }
            else
            {
                wygrana = 0;
                cout << "Niestety, jest to bledna odpowiedz. Konczysz gre z " << wygrana_gwarantowana << " zl." << endl; // Wyświetla gwarantowaną wygraną
                break;
            }

            aktualne_pytanie++;
            ilosc_udzielonych_odpowiedzi++;

            // Sprawdza, czy osiągnięto gwarantowaną wygraną
            if (wygrana == 1000 || wygrana == 40000)
            {
                osiagnieto_gwarantowana_wygrana = true;
                wygrana_gwarantowana = wygrana;
            }

            if (ilosc_udzielonych_odpowiedzi == 12) // Po odpowiedzeniu na 12 pytań, zakończ grę
            {
                cout << "Odpowiedziales na 12 pytan! Gratulacje!" << endl;
                break;
            }
        }

        
        
            cout << "\nDziekuje za gre!" << endl;
        
    }
};

int main()
{
    Milionerzy game;
    cout << "Witaj w grze Milionerzy!" << endl;
    game.mechanika();

    return 0;
}