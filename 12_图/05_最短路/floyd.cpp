#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

//传入邻接矩阵

void PrintPath(vector<vector<int>>&path, int i, int j){
    int t = j;
    vector<int>p;
    p.push_back(t);
    while (t != i){
        t = path[i][t];
        p.push_back(t);
    }
    reverse(p.begin(), p.end());
    for(auto node : p){
        cout << node << " ";
    }
}

void Floyd(vector<vector<int>>graph, int n){
    //存距离和路径
    vector<vector<int>>dist(n, vector<int>(n));
    vector<vector<int>>path(n, vector<int>(n));
    //初始化
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = graph[i][j];
            if(i == j || dist[i][j] == INF){
                path[i][j] = -1;
            }else{
            path[i][j] = i;
            }
        }
    }
    //开始更新，依次将每个点作为中心点k
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    //输出
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //如果存在路径
            if(dist[i][j] < INF){
                cout << "从点" << i << "到点" << j << "的最短距离为" << dist[i][j];
                //最短路径不能直接输出，要用函数
                PrintPath(path,i,j);
            }
        }
    }