#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

class QueueLinked{
public:
    Node *front, *rear;
    //构造函数
    QueueLinked(){
        front = NULL;
        rear = NULL;
    }
//是尾插吧 第一个front = s   rear = s  后面的就rear->next = s rear = s
    void push(int x){
        Node *s = new Node;
        s->val = x;
       s->next = NULL;
	if(front == NULL){
	front = s;
	rear = s;
}else{
	rear->next = s;
	rear = s;
}
    }
//头删
    void pop(){
	Node* p = front;
    front = front->next;
    delete p;

    if(front == NULL){
        rear = NULL;
    }
}
    int getFront(){
	return front->val;
    }
    bool empty(){
	return front == NULL;
    }
    //析构函数
    ~QueueLinked(){
	while(front != NULL){
		Node *p = front;
		front = front->next;
		delete p;
}
    }
};