// program symulujacy bank
// Grzegorz Piotrowski, gr.piotro@gmail.com

#include <iostream>
using namespace std;

class Osoba {
public:
char* imie;
int wiek;

    Osoba(char* i, int w) {
        imie = i;
        wiek = w;
    }

    ~Osoba() {
        cout << "Skasowano: " << imie << endl;
    }

    /*//zad 1,2,3
    Osoba(char* i, int w) {
        imie = i;
        wiek = w;
    }
    
    // lista inicjalizacyjna
    Osoba(char* i, int w) : imie(i), wiek(w) {
        cout << "Konstruktor z lista inicjalizacyjna" << endl;

    }

    /
    Osoba() {
        char k[] = "Stefan";
        imie = k;
        wiek = 30;
        cout << "Konstruktor pusty" << endl;
    }

    ~Osoba() {
        cout << "Destruktor dla: " << imie << endl;
    }

    // konstruktor kopiujący
    
    Osoba(Osoba& o) {
        imie = o.imie;
        wiek = o.wiek;
    }
    */
};

class Rachunek {
public:
Osoba* wlas;
double stan_konta;

    Rachunek(Osoba* o, double stan) {
        wlas = o;
        stan_konta = stan;
    }

    Rachunek() {
        wlas = nullptr;
        stan_konta = 0;
    }
};

class Bank {
public:
Rachunek* lista[10];
static int counter; 
char t[6] = "pusty";

    Rachunek* otworzNowyRachunek(Osoba* os, double s) {
        Rachunek* r = new Rachunek(os, s);
        lista[counter++] = r;
        cout << "Utworzono nowy rachunek dla: " << os->imie << "." << endl;
        return r;
    }

    void zmienWlaciciela(Rachunek* r, Osoba* n) {
        Rachunek* to_change;
        for(int i = 0; i < 10; i++)
            if(lista[i] == r)
                to_change = lista[i];
        to_change->wlas = n; 
        cout << "Zmieniono wlasciciela rachunku." << endl;   
    }

    void usunRachunek(Rachunek* r) {
        for(int i = 0; i < counter; i++)
            if(lista[i] == r)
                lista[i] = new Rachunek(new Osoba(t, 0), 0.0);
        cout << "Skasowano rachunek." << endl;
    }

    Rachunek* getRachunek(int pos) {
        return lista[pos];
    }
    
    void drukujStan() {
        for(int i = 0; i < counter; i++) {
            cout << "Rachunek nr: " << i << " , wlasciciel: " << lista[i]->wlas->imie << " , stan konta: " 
            << lista[i]->stan_konta << '.' << endl;
        }
    }
};
int Bank::counter = 0;

/*
void printAll(Osoba& o) {
        cout << "Imie: " << o.imie << endl;
        cout << "Wiek: " << o.wiek << endl;
}

void printAll(Osoba* o) {
        cout << "Imie: " << o->imie << endl;
        cout << "Wiek: " << o->wiek << endl;
}
*/

int main() 
{
    Bank* bank = new Bank();
    
    char tomek[] = "Tomek";
    char malgorzata[] = "Malgorzata";
    Osoba* Tomek = new Osoba(tomek, 45);
    Osoba* Malgorzata = new Osoba(malgorzata, 43);

    bank->otworzNowyRachunek(Tomek, 100.0);
    bank->drukujStan();

    bank->otworzNowyRachunek(Tomek, 100.0);
    bank->drukujStan();

    bank->otworzNowyRachunek(Tomek, 100.0);
    bank->drukujStan();

    bank->zmienWlaciciela(bank->getRachunek(0), Malgorzata);
    bank->drukujStan();

    bank->usunRachunek(bank->getRachunek(1));
    bank->drukujStan();

    //Zad 1,2,3
    /*
    char i[] = "Marek";
    char j[] = "Marcin";
    
    Osoba* marek = new Osoba(i, 15);
    Osoba marcin = Osoba(j, 19);

    //Osoba* marek2 = new Osoba(*marek);

    Osoba* stefan = new Osoba();

    printAll(marek);
    //printAll(marek2);
    printAll(stefan);
    printAll(marcin);

    delete marek;
    delete stefan;

    cout << "Kolejne zadanie" << endl;

    char g[] = "Ania";

    Osoba* ania = new Osoba(g, 22);
    printAll(ania);

    Osoba& dupa = *ania;

    Osoba* d = new Osoba(dupa);

    printAll(ania);
    printAll(d);

    delete ania;
    
    printAll(d);
    */

}
