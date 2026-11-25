#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>Adj(int n, vector<vector<int>>&edges);
void Dfs(int i, vector<vector<int>>&adj, vector<bool>& visited);

int main(){
    //输入n个结点和m个边
    int n, m;
    cin >> n >> m;

    vector<vector<int>>edges;
    vector<bool> visited(n+1, false);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
    }

    vector<vector<int>>adj = Adj(n, edges);
    Dfs(1, adj, visited);

    return 0;
}

//传进来一个结点的最大编号n，一个边集edges
vector<vector<int>>Adj(int n, vector<vector<int>>&edges){
    //根据结点和边集建立邻接表
    //为了让结点编号直接和下标对应，把下标0空出来
    vector<vector<int>>adj(n+1);
    for(auto edge : edges){
        int a = edge[0];
        int b = edge[1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return adj;
}

void Dfs(int i, vector<vector<int>>&adj, vector<bool>& visited){
    visited[i] = true;
    cout << i << " ";

    for(auto k : adj[i]){
        if (!visited[k]){
            Dfs(k, adj, visited);
        }
    }
}