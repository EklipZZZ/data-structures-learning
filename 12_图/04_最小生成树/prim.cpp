#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
//我们写哪种好呢，是邻接矩阵还是邻接表？
//这是没有堆和优先队列的，先写邻接矩阵吧
struct Edge{
    int u, v;
    int w;
};

vector<vector<int>> MatrixGraph(int n, vector<Edge>&edges){
    vector<vector<int>> graph(n, vector<int>(n,INF));
    for(int i = 0; i < n; i++){
        graph[i][i] = 0;
    }
    for(auto edge : edges){
        int a = edge.u;
        int b = edge.v;

        graph[a][b] = edge.w;
        graph[b][a] = edge.w;
    }
    return graph;
}

int Prim(int s, vector<vector<int>>&graph){
    int n = graph.size();
    vector<int>lowcost(n);
    //初始化
    for(int i = 0; i < n; i++){
        lowcost[i] = graph[s][i];
    }
    int sum = 0;
    //再找n-1个
    for(int i = 1; i < n; i++){
        int mindist = INF;
        int k = -1;
        for(int j = 0; j < n; j++){
            if(lowcost[j]!=0 && lowcost[j] < mindist){
                mindist = lowcost[j];
                k = j;
            }
        }
        //不连通
        if(k == -1){
            return -1;
        }

        sum += mindist;
            lowcost[k] = 0;
            //更新新点
            for(int j = 0; j < n; j++){
                if(lowcost[j] != 0 && graph[k][j] < lowcost[j]){
                    lowcost[j] = graph[k][j];
                }
            }
    }
    return sum;
}



int main(){
    int n, m;

    // n个顶点，m条边
    cin >> n >> m;

    vector<Edge> edges(m);

    // 输入每条边：起点 终点 权值
    for(int i = 0; i < m; i++){
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    vector<vector<int>> graph = MatrixGraph(n, edges);

    // 这里从0开始
    int sum = Prim(0, graph);

    if(sum == -1){
        cout << "图不连通" << endl;
    }else{
        cout << "最小生成树总权值: " << sum << endl;
    }

    return 0;
}