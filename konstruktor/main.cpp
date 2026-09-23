#include <iostream>

using namespace std;
//struktura kolejka
struct kolejka
{
    int nr;
    kolejka* nastepny;

    kolejka(int _nr)
    {
        nr=_nr;
        nastepny=nullptr;
    }
};

class uczen
{
    kolejka* poczatek;
    kolejka* koniec;

public:
    //konstruktor tworzy pust¹ kolejkê
    uczen()
    {
        poczatek=nullptr;
        koniec=nullptr;
    }
    //funkcja dodaj, dodaje nowy element na koniec kolejki, int nr przechowuje dodawana liczbe
    int dodaj(int nr)
    {
        kolejka* nowy=new kolejka(nr);

        if (poczatek==nullptr)
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

        while (temp!=nullptr)
        {
            cout<<temp->nr<<endl;
            temp=temp->nastepny;
        }
    }
    //funkcja usun, usuwa wszystkie elementy kolejki
    void usun()
    {
        while (poczatek!=nullptr)
        {
            kolejka* temp=poczatek;
            poczatek=poczatek->nastepny;
            delete temp;
        }
        koniec = nullptr;
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

    u.dodaj(10);
    u.dodaj(12);
    u.dodaj(34);
    u.dodaj(41);

    u.wypisz();
    return 0;
}
