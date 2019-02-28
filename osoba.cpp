// funkcja fun zwraca ilosc liter w imieniu tej z osob a i b, ktora ma dluzsze nazwisko
// Grzegorz Piotrowski, gr.piotro@gmail.com

#include <iostream>
using namespace std;

struct Osoba {
    char* imie;
    char* nazwisko;

    Osoba(char* i, char* n) {
        imie = i;
        nazwisko = n;
    }
};

void print(Osoba* o){
    cout << o->imie << " ";
    cout << o->nazwisko << endl;
}

int count(char* s) {
   int counter = 0;
   do
   {
       counter++;
   } while (*s++);
   return counter-1;    
}

int fun(Osoba& a, Osoba* b) {
    int i1 = count(a.imie);
    int i2 = count(b->imie);
    int n1 = count(a.nazwisko);
    int n2 = count(b->nazwisko);

    if (n1 > n2)
        return i1;
    else
        return i2;
}

int main() 
{
    char imie1[] = "Marian";
    char imie2[] = "Stefbebebe";
    char nazwisko1[] = "Menobenobele";
    char nazwisko2[] = "Dupelela";

    Osoba a = Osoba(imie1, nazwisko1);
    Osoba b = Osoba(imie2, nazwisko2);

    int c = count(b.nazwisko);
    cout << c << endl;

    print(&a);
    print(&b);

    cout << "Odpowiedz:" << endl;
    int o = fun(a, &b);
    cout << o;


}
