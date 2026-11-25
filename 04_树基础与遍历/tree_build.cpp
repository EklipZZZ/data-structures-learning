//递归建树
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};
//根左右，建树是先序遍历
Node* CreateTree(){
    int x;
    cin >> x;

    if(x == -1){
        return nullptr;
    }else{
        Node* root = new Node;
        root->val = x;
        root->left = CreateTree();
        root->right = CreateTree();
        return root;
    }
}
//左右根，删树是后序遍历
void DeleteTree(Node* root){
    if(root == nullptr){
        return;
    }

    DeleteTree(root->left);
    DeleteTree(root->right);

    delete root;
}

int main(){
    Node *root = CreateTree();
    cout << root->val << endl;
    DeleteTree(root);
    return 0;
}