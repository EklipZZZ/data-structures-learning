#include<bits/stdc++.h>
using namespace std;

class StackArray{
private:
    int data[100];
    int top;
public:
    StackArray(){
        top = -1;
    }

    void push(int x){
        top++;
        data[top] = x;
    }
    void pop(){
        top--;
    }
    int getTop(){
        return data[top];
    }
    bool empty(){
        return top == -1;
    }
};
