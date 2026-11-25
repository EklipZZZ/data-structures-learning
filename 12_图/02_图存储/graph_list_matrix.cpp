#include <bits/stdc++.h>
using namespace std;

//改成一个函数
//n是结点编号，m是边数
vector<vector<int>> MatrixGraph(int n, vector<vector<int>>&edges){
    //把下标为0的结点空出来
    vector<vector<int>> graph(n+1, vector<int>(n+1,0));

    for(auto edge : edges){
        int a = edge[0];
        int b = edge[1];

        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    return graph;
}

vector<vector<int>> ListGraph(int n, vector<vector<int>>&edges){
    //含n+1个数组的数组
    vector<vector<int>> adj(n+1);
    //并不是遍历每个adj，而是遍历边随查随插adj
    for(auto edge : edges){
        int a = edge[0];
        int b = edge[1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return adj;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>>edges;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
    }    
    vector<vector<int>>matrix = MatrixGraph(n, edges);
    vector<vector<int>>list = ListGraph(n, edges);

    return 0;
}