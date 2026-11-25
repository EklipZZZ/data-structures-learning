#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prior;
    Node* next;
};

void PrintList(Node* L){
    //先跳过头结点
    L = L->next;
    while(L != NULL){
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}
// 正向遍历

Node* FindKth(Node* L, int k){
    //这里的p是为了不更改L
    Node *p = L;
    //头结点就是第0个
    for (int i = 0; i < k&&p != NULL; i++){
        p = p->next;
    }
    return p;
}
// 找第 k 个

//下面两个才不同：要同时修改双指针
bool Insert(Node* L, int k, int e){
    Node *p = FindKth(L, k-1);
    Node *s = new Node;
    s->data = e;
    s->next = p->next;
    s->prior = p;
    if (p->next != NULL) p->next->prior = s;
    p->next = s;
    return true;
}

bool Delete(Node* L, int k){
    Node *p = FindKth(L, k);
    p->prior->next = p->next;
    if (p->next != NULL) p->next->prior = p->prior;
    delete p;
    return true;
}