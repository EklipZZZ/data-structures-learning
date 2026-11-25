#include <bits/stdc++.h>
using namespace std;

struct Node{
    char ch;        // 字符，内部结点可以不用
    int weight;     // 权值
    Node* left;
    Node* right;
};

// priority_queue 默认大根堆，所以这里反过来写成小根堆
struct cmp{
    bool operator()(Node* a, Node* b){
        return a->weight > b->weight;
    }
};

// 构造哈夫曼树
Node* CreateHuffmanTree(vector<pair<char,int>>& data){
    priority_queue<Node*, vector<Node*>, cmp> q;

    // 先把所有字符结点放进去
    for(auto x : data){
        Node* p = new Node{x.first, x.second, nullptr, nullptr};
        q.push(p);
    }

    // 每次取两个最小的
    while(q.size() > 1){
        Node* a = q.top();
        q.pop();

        Node* b = q.top();
        q.pop();

        // 合成父结点
        Node* parent = new Node{
            '\0',
            a->weight + b->weight,
            a,
            b
        };

        // 父结点重新放回候选池
        q.push(parent);
    }

    return q.top();
}

// 左0右1，输出哈夫曼编码
void PrintCode(Node* root, string code){
    if(root == nullptr){
        return;
    }

    // 叶子结点才是真正的字符
    if(root->left == nullptr && root->right == nullptr){
        cout << root->ch << " : " << code << endl;
        return;
    }

    PrintCode(root->left, code + "0");
    PrintCode(root->right, code + "1");
}

// 后序释放整棵树
void DeleteTree(Node* root){
    if(root == nullptr){
        return;
    }

    DeleteTree(root->left);
    DeleteTree(root->right);

    delete root;
}

int main(){
    vector<pair<char,int>> data = {
        {'A', 1},
        {'B', 1},
        {'C', 1},
        {'D', 1},
        {'E', 1}
    };

    Node* root = CreateHuffmanTree(data);

    PrintCode(root, "");

    DeleteTree(root);

    return 0;
}