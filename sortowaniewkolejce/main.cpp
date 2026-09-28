#include <iostream>
#include <fstream>

using namespace std;
//struktura kolejka
struct kolejka
{
    int nr;
    kolejka* nastepny;

    kolejka(int _nr)
    {
        nr=_nr;
        nastepny=NULL;
    }
};

class uczen
{
    kolejka* poczatek;
    kolejka* koniec;

public:
    //konstruktor tworzy pusta kolejkê
    uczen()
    {
        poczatek=NULL;
        koniec=NULL;
    }
    //funkcja dodaj, dodaje nowy element na koniec kolejki, int nr przechowuje dodawana liczbe
    int dodaj(int nr)
    {
        kolejka* nowy=new kolejka(nr);

        if (poczatek==NULL)
        {
            poczatek=nowy;
            koniec=nowy;
        }
        else
        {
            koniec->nastepny=nowy;
            koniec=nowy;
        }
        return nr;
    }
    //funkcja wypisz, wypisuje wszystkie elementy kolejki
    void wypisz()
    {
        kolejka* temp=poczatek;

        while (temp!=NULL)
        {
            cout<<temp->nr<<endl;
            temp=temp->nastepny;
        }
    }
    //funkcja usun, usuwa wszystkie elementy kolejki
    void usun()
    {
        while (poczatek!=NULL)
        {
            kolejka* temp=poczatek;
            poczatek=poczatek->nastepny;
            delete temp;
        }
        koniec = NULL;
    }
    //funkcja do wczytania elementow z pliku do kolejki
    void wczytaj_z_pliku()
    {
        ifstream plik("a.txt");
        usun();
        int liczba;
        while(plik>>liczba)
        {
            dodaj(liczba);
        }
        plik.close();
        cout<<"Wczytano z pliku"<<endl;
    }
    void sort_bubble()
    {
        //zamien wskaznik
        if (poczatek==NULL || poczatek->nastepny==NULL)
        {
            return;
        }
        bool zamiana;
        kolejka* temp;
        kolejka* koniec_sortowania = NULL;
        do
        {
            zamiana=false;
            temp=poczatek;
            while (temp->nastepny!=koniec_sortowania)
            {
                if (temp->nr>temp->nastepny->nr)
                {

                    int t = temp->nr;
                    temp->nr = temp->nastepny->nr;
                    temp->nastepny->nr = t;
                    zamiana = true;
                }
                temp=temp->nastepny;
            }
            koniec_sortowania=temp;
        }
        while(zamiana);
        cout<<"Posortowano"<<endl;
    }
    void zapisz_do_pliku()
    {
        ofstream plik("b.txt");

         kolejka* temp=poczatek;
        while (temp!=NULL)
        {
            plik<<temp->nr<<endl;
            temp=temp->nastepny;
        }
        plik.close();
        cout<<"Zapisano do pliku"<<endl;
    }

    void menu()
    {
        int wybor;
        do
        {
        cout<<"=-=-=-=-=-=-=-=-=-=-=MENU-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"1 - Wczytaj z pliku"<<endl;
        cout<<"2 - Wypisz kolejke"<<endl;
        cout<<"3 - Posortuj kolejke"<<endl;
        cout<<"4 - Zapisz do pliku"<<endl;
        cout<<"0 - Zamknij program"<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<endl;
        cout<<"Wybor: ";
        cin>>wybor;
        switch(wybor)
            {
                case 1:
                    wczytaj_z_pliku();
                    break;
                case 2:
                    wypisz();
                    break;
                case 3:
                    sort_bubble();
                    break;
                case 4:
                    zapisz_do_pliku();
                    break;
                case 0:
                    cout<<"Koniec programu"<<endl;
                    break;
                default:
                    cout<<"Nie ma takiego wyboru. Sprobuj ponownie"<<endl;
            }
        }
        while(wybor!=0);
        }
    //destruktor usuwa kolejkê po zakoñczeniu programu
    ~uczen()
    {
        usun();
    }
};

int main()
{
    uczen u;
    u.menu();
    return 0;
}
