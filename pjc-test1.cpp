// funkcja, ktora pobiera dwa odcinki, przez wskaznik i referencje a zwraca przez wskaznik dluzszy z nich
// Grzegorz Piotrowski, gr.piotro@gmail.com

#include <iostream>
using namespace std;

struct Interval {
    double a, b;

    Interval(double p, double k) {
        a = p;
        b = k;
    }
   
};

const Interval* longer(const Interval* ps, const Interval& rs) {
    double ps_length, rs_length;
    ps_length = ps->b - ps->a;
    rs_length = rs.b - rs.a;
    if(ps_length >= rs_length)
        return ps;
    if(ps_length < rs_length)
        return &rs;
}

int main() 
{
    Interval a = Interval(5.0, 13.0);
    Interval b = Interval(5.0, 10.0);
    const Interval* c = longer(&a, b);

    cout << "a: " << c->a << " b: " << c->b;
}
