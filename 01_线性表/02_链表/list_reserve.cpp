#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//比如这里的p就是传入链表的头
Node* reverse_iteration(Node *p){
    Node *prv, *cur, *next;
    cur = p;
    //最后一定要指向NULL
    prv = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prv;
        prv = cur;
        cur = next;
    }
    return prv;
}

Node* reverse_recursion(Node *p){
    if (p == NULL || p->next == NULL){
        return p;
    }
    Node *head= reverse_recursion(p->next);
    p->next->next = p;
    p->next = NULL;
    return head;
}