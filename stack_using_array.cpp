#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    cout << "Enter size of stack : ";
    cin >> st->size;
    st->top = -1;
    st->S = new int[st->size];
}

void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        cout << st.S[i]<<" ";
    cout << endl;
}

void Push(struct Stack *st, int x)
{
    if(st->top==st->size-1)
        cout << "Stack Overflow \n";
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;

    if(st->top==-1)
        cout << "Stack Underflow \n";
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top-index+1<0)
        cout << "Invalid index \n";
    else
        x = st.S[st.top - index + 1];

    return x;
}

int isEmpty(struct Stack st)
{
    return st.top == -1;
}

int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main(){
    struct Stack st;
    Create(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    // cout << Pop(&st)<<endl;
    cout << Peek(st, 4)<<endl;
    Display(st);
    return 0;
}