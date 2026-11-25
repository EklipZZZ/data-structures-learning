#include<bits/stdc++.h>
using namespace std;

class QueueArray{
private:
    int data[100];
    int front, rear;
public:
    //构造函数
    QueueArray(){
        front = 0;
        rear = 0;
    }
    void push(int x){
        data[rear] = x;
        rear++;
    }
    void pop(){
        front++;
    }
    int getFront(){
        return data[front];
    }
    bool empty(){
        return front == rear;
    }
}