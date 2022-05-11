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

class SpecialStack
{
Stack stack;
Stack auxStack;
public:
void push(int data)
{
    if(stack.isFull()) return;
    if(auxStack.isEmpty())
    {
        auxStack.push(data);
    }
    int y=auxStack.pop();
    auxStack.push(y);
    if(data<=y){
        auxStack.push(data);
    }
    stack.push(data);

}
int pop()
{
    if(stack.isEmpty()) return -1;
    int y=stack.pop();
    int x=auxStack.pop();
    if(y!=x) auxStack.push(x);
    return y;

}
int getMin() // O(1)
{
    int x=auxStack.pop();
    auxStack.push(x);
    return x;

}
};

int main()
{
    SpecialStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.getMin()<<endl;
    st.push(30);
    st.push(40);
    st.pop();
    st.pop();
    cout<<st.getMin()<<endl;
    return 0;
}
