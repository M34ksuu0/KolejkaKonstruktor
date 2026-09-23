# Kolejka uczniów

Program w języku C++, który przedstawia działanie kolejki za pomocą struktury oraz klasy.

Opis programu

Program tworzy kolejkę dynamiczną, w której każdy element przechowuje liczbę nr oraz wskaźnik na następny element kolejki.

Klasa uczen zarządza kolejką i posiada funkcje umożliwiające:

dodawanie elementów,

wyświetlanie elementów,

usuwanie elementów.

Struktura kolejka

Struktura kolejka zawiera:

int nr – przechowuje liczbę,

kolejka* nastepny – wskaźnik na następny element kolejki.

Konstruktor struktury ustawia przekazaną liczbę oraz ustawia wskaźnik nastepny na nullptr.

Klasa uczen

Klasa posiada dwa wskaźniki:

poczatek – wskazuje na pierwszy element kolejki,

koniec – wskazuje na ostatni element kolejki.

Funkcje klasy
uczen()

Konstruktor tworzy pustą kolejkę, ustawiając poczatek i koniec na nullptr.

dodaj(int nr)

Dodaje nowy element na koniec kolejki.

Parametr nr przechowuje liczbę, która zostanie dodana do kolejki.

wypisz()

Przechodzi przez całą kolejkę i wypisuje wszystkie znajdujące się w niej liczby.

usun()

Usuwa wszystkie elementy kolejki z pamięci za pomocą delete.

~uczen()

Destruktor automatycznie wywołuje funkcję usun(), dzięki czemu wszystkie elementy kolejki zostają usunięte po zakończeniu działania obiektu.

Przykład działania

W funkcji main() do kolejki dodawane są liczby:

u.dodaj(10);
u.dodaj(12);
u.dodaj(34);
u.dodaj(41);


Następnie funkcja:

u.wypisz();


wyświetla:

10
12
34
41


Po zakończeniu programu destruktor usuwa wszystkie elementy kolejki.

Technologie

C++

dynamiczna alokacja pamięci (new)

zwalnianie pamięci (delete)

wskaźniki

struktury

klasy

konstruktor i destruktor
