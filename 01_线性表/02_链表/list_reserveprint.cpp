#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void print_reverse_iteration(Node *p){
    //需要用到栈
    stack<int>st;
    
    while (p != NULL){
        st.push(p->data);
        p = p->next;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}

void print_reverse_recursion(Node *p){
    if (p == NULL){
        cout << endl;
        return;
    }
    print_reverse_recursion(p->next);
    cout << p->data;
}