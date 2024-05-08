#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void Push(int  x){
    struct Node *t;
    t = new Node;
    if(t==NULL)
        cout << "stack is full\n";
    else{
        t->data = x;
        t->next=top;
        top = t;
    }
}

int Pop(){
    struct Node *t;
    int x = -1;
    if(top==NULL)
        cout << "stack is empty\n";
    else{
        t = top;
        top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display(){
    struct Node *p;
    p = top;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(60);
    Push(70);
    Display();
    cout<<Pop();

    return 0;
}