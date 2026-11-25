#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

class StackLinked{
public:
    Node* top;
    //构造函数
    StackLinked(){
        top = NULL;
    }
    void push(int x){
        Node* s = new Node;
        s->val = x;
        s->next = top;
        top = s;
    }
    void pop(){
        Node* p = top;
        top = top->next;
        delete p;
    }
    int getTop(){
        return top->val;
    }
    bool empty(){
        return top == NULL;
    }
    //析构函数
    ~StackLinked(){
        while(top != NULL){
            Node* p = top;
            top = top->next;
            delete p;
        }
    }
};