#include<iostream>
using namespace std;

class Stack
{
int stack[100];
int top;
public:
Stack()
{
    this->top = -1;
}
void push(int value)
{
   if(isFull()) return;
   top++;
   stack[top] = value;
}
int pop()
{
    if(isEmpty()) return -1;
    int x=stack[top];
    top--;
    return x;

}
void printStack()
{
    for(int i=top;i>=0;i--) cout<<stack[i]<<endl;

}
bool isEmpty()
{
    return top == -1;

}
bool isFull()
{
    return top == 100;

}
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(30);
    st.push(40);
    st.printStack();
    st.pop();
    st.pop();
    st.printStack();
    return 0;
}
