#include<bits/stdc++.h>
using namespace std;
//Bfs用队列
//先写邻接矩阵版
void bfs_matrix(int i, vector<vector<int>>&graph, vector<bool>&visited){
    int n = graph.size();
    queue<int>q;
    visited[i] = true;
    q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();    

        cout << u << " ";
        for(int k = 0; k < n; k++){
            if(graph[u][k] && !visited[k]){
                q.push(k);
                visited[k] = true;
            }
        }
    }
}
//再写邻接表版本
void bfs_adj(int i, vector<vector<int>>&adj, vector<bool>&visited){
    queue<int>q;
    visited[i] = true;
    q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();    

        cout << u << " ";
        for(auto k : adj[u]){
            if(!visited[k]){
                q.push(k);
                visited[k] = true;
            }
        }
    }
}