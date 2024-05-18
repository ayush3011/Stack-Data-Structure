#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x){
    struct Node *t;
    t = new Node;

    if(t==NULL)
        cout << "stack is full" << endl;
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop(){
    struct Node *t;
    char x =-1;

    if(top==NULL)
        cout << "stack is empty" << endl;
    else{
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display(){
    struct Node *p;
    p = top;
    while (p!=NULL)
    {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

int isBalanced(char *exp)
{
    int i; 
    for ( i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')'){
            if(top==NULL)
                return 0;
            pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

// Function to check if a given pair of parentheses is matching
int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// Function to check if the expression is balanced
int isBalancedDifferent(char *exp) {
    int i;
    char x;
    struct StackNode* stack = NULL;

    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is an opening bracket, push it onto the stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&stack, exp[i]);
        }
        // If the character is a closing bracket
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            // If stack is empty, return false
            if (isEmpty(stack)) {
                return 0;
            }
            // Pop the top element from the stack
            else {
                x = pop(&stack);
                // If the popped element does not match the current closing bracket, return false
                if (!isMatchingPair(x, exp[i])) {
                    return 0;
                }
            }
        }
    }

    // If the stack is empty, return true, otherwise return false
    return isEmpty(stack);
}


int main(){
    char *exp = "((a+b)*(c-d))";
    cout<<isBalanced(exp);
    return 0;
}
