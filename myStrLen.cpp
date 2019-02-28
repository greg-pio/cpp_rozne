// zwraca dlugosc ciagu znakow
// Grzegorz Piotrowski, gr.piotro@gmail.com

#include <iostream>
using namespace std;

int mystrlen(char* t) {
    int count = 0;
    while (*t++)
        count++;
    return count;
}

int main() 
{ 
    char tab[] = "Fantasmagoria";
    cout << "Sizeof: " << sizeof(tab)-1 << endl;
    cout << "Mystrlen: " << mystrlen(tab) << endl;


}
