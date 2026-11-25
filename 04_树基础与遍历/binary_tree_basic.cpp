#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
};

int main(){
    Node* root = new Node{1, nullptr, nullptr};
    Node* a = new Node{2, nullptr, nullptr};
    Node* b = new Node{3, nullptr, nullptr};

    root->left = a;
    root->right = b;

    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    return 0;
}