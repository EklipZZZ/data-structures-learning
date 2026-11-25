#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//dijkstra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
        //编号是1到n
        vector<int>dist(n+1, INF);
        //小根堆
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >pq;

        dist[k] = 0;
        pq.push({dist[k], k});

        while(!pq.empty()){
            //小根堆，自动对目前最短的操作
            int d = pq.top().first;
            int u = pq.top().second;

            pq.pop();
            //前面已经有过了
            if(d > dist[u]){
                continue;
            }

            for(auto time : times){
                //看看这个新点能不能更新一些距离
                if(time[0] == u){
                    int v = time[1];
                    int w = time[2];
                    
                    if(dist[u] + w < dist[v]){
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        //也要把0空出来
        for(int i = 1; i <= n; i++){
            if(dist[i] == INF){
                return -1;
            }
        }
        //也要把0空出来
        return *max_element(dist.begin()+1, dist.end());
    }
};