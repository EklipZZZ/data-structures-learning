#include<bits/stdc++.h>
using namespace std;
//Kahn's Algorithm
#define INF 1e9
//有向无环图
//可以藉此来判断有没有环
//每次选入度为0的点，删除这个点和他的出边
//不唯一
//邻接矩阵版
bool toposort(vector<vector<int>>&graph, int n){
    stack<int>s; //顺序栈
    vector<int>indeg(n); //存入度
    //计算所有顶点入度
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(graph[i][j]) indeg[j] ++;
        }
    }
    //用栈存入度为0的顶点
    for(int i = 0; i < n; i++){
        if(!indeg[i]){
            s.push(i);
        }
    }
    int cnt = 0; //统计次数，看看是不是都排序了
    //每次选入度为0的点，删掉它和它的出边
    while(!s.empty()){
        int ch = s.top();
        s.pop();
        cnt++;
        for(int i = 0; i < n; i++){
            //如果邻接
            if(graph[ch][i]){
                indeg[i]--;
                //因此变成0了就也进栈
                if(!indeg[i]){
                    s.push(i);
                }
            }
        }
    }
    if(cnt==n)return true;
    return false;
}
//再写一个邻接表版本
bool toposort_adj(vector<vector<int>>&adj, int n){
    stack<int>st;
    vector<int>indeg(n);
    for(int i = 0; i < n; i++){
        for(auto j : adj[i]){
            indeg[j]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(!indeg[i]) st.push(i);
    }

    int cnt = 0;

    while(!st.empty()){
        int s = st.top();
        st.pop();
        cnt++;

        for(auto j : adj[s]){
            indeg[j]--;
            if(!indeg[j]){
                st.push(j);
            }
        }
}
    if(cnt == n) return true;
    return false;
}