// funkcja znajduje najmniejszy element tablicy
// Grzegorz Piotrowski, gr.piotro@gmail.com

#include <iostream>
using namespace std;

int& checkTab(const int* t, int wym) {
    static int min = t[0];
    for(int i = 0; i < wym; i++) {
        if(t[i] < min)
            min = t[i];
    }
    return min;
}

int main() 
{
    int tab[] = {3, 4, 1, 1, 0}; 
    int a = checkTab(tab, 5);
    cout << "Min: " << a;

}
