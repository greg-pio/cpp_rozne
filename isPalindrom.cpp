// sprawdza czy dany ciag znakow jest palindromem
// Grzegorz Piotrowski, gr.piotro@gmail.com

#include <iostream>
using namespace std;

int mystrlen(char* t) {
    int count = 0;
    while (*t++)
        count++;
    return count;
}

bool isPalindrom(char* c) {

    int size = mystrlen(c);
    char* end = c + size - 1;

    while(*c++ < *end--)
        if (*c != *end)
            return 0;
    
    return 1;
}

int main() 
{
    char tab[] = "ABBA";

    if (isPalindrom(tab))
        cout << "To jest palindrom";
    else
        cout << "To nie jest palindrom" << endl;

}
