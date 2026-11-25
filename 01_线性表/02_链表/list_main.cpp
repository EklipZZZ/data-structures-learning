#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

//输出
void PrintList(Node *L){
    Node *p = L->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//查值
Node *Find(Node *L, int e){
    Node *p = L->next;
    while (p != NULL&&p->data != e){
        p = p->next;
    }
    return p;
}
    //查位序
Node *FindKth(Node *L, int k){
    Node *p = L;
    //头结点就是第0个
    for (int i = 0; i < k&&p != NULL; i++){
        p = p->next;
    }
    return p;
}
    //插入到第k个
bool Insert(Node *L, int k, int e){
        if (k < 1){
        return false;
    }
        //先找到前一个
        Node *p = FindKth(L, k-1);
        if (p==NULL){
            return false;
        }
        //进行尾插
        Node *s = new Node;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
    //删除
bool Delete(Node *L, int k){
        if (k < 1){
        return false;
    }
        //单链表没有prior，还是得从k-1个开始处理
        Node *p = FindKth(L, k-1);
        if (p==NULL||p->next == NULL){
            return false;
        }
        Node *s = p->next;
        p->next = s->next;
        //释放内存
        delete s;
        return true;
    }

int main(){
    //L指向头结点
    Node *L = new Node;
    L->next = NULL;
    int n;
    cin >> n;
    cout << "请选择建表方式：1-尾插 2-头插\n";
    int mode;
    cin >> mode;

    if (mode == 1){
    //尾插
    //tail也指向头结点
    Node *tail = L;
    for(int i = 0; i < n; i++){
        Node *s = new Node;
        cin >> s->data;
        s->next = NULL;
        //第一次是头结点一起指向s，后面是tail指向s
        tail->next = s;
        //这个s成为了新的tail
        tail = s;
    }
}
    if(mode == 2){
    //头插
    for(int i = 0; i < n; i++){
        Node *s = new Node;
        cin >> s->data;
        //s指向首元节点
        s->next = L->next;
        //头结点指向s，s成为首元节点
        L->next = s;
    }
}
    PrintList(L);
    Node* p = Find(L, 20);
if (p != NULL)
    cout << "找到了：" << p->data << endl;
else
    cout << "没找到" << endl;
    Insert(L, 2, 99);
PrintList(L);
Delete(L, 3);
PrintList(L);   
    return 0;
}