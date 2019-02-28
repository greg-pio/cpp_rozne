// zabawa z lista - funkcja fun zamienia miejscami dane (int data) w elementach pierwszym i ostatnim
// Grzegorz Piotrowski, gr.piotro@gmail.com

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

void fun(Node* n) {
    Node* h = n;    
    int head = n->data;
    while(n->next != nullptr)
        n=n->next;
    int tail = n->data;
    Node* t = n;
    h->data = tail;
    t->data = head;
}

void printData(Node* n) {
    for ( ; n; n=n->next) {
        cout << n->data << endl;
    }
}

int main() 
{
   Node czwarty = Node(1, nullptr);
   Node trzeci = Node(2, &czwarty);
   Node drugi = Node(8, &trzeci);
   Node pierwszy = Node(6, &drugi); 

   Node* head = &pierwszy;

   printData(head);

   fun(head);
    cout << endl;

   printData(head);



}
