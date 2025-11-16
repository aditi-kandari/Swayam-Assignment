// Implement Stack using array in c++

#include <iostream>
using namespace std;
#define MAX 1000
class Stack {
    int top=-1;
    int a[1000];

    //push function to add an item to stack. It increases top by 1
    void push(int x){
        if(top>=MAX-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            a[top]=x;
        }
    }
    
    //pop function to remove an item from stack. It decreases top by 1
    void pop(){
        if(top<0){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            int x=a[top];
            top--;
        }
    }
    
    //top function to get the top item in the stack
    int top(){
        if(top<0){
            cout<< "Stack is empty"<<endl;
            return -1;
        }
        else{
            return a[top];
        }
    }
};    