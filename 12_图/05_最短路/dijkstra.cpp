#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF=0x3fffffff;
        vector<vector<int>> G(n+1,vector<int> (n+1,INF));
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            G[u][v]=w;
        }
        vector<int> d(n+1,INF);
        d[k]=0;
        vector<bool> vis(n+1,0);
        for(int i=0;i<n;i++){
            int u=-1,mini=INF;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&d[j]<mini){
                    mini=d[j];
                    u=j;
                }
            }
            if(u==-1)
                return -1;
            vis[u]=1;
            for(int v=1;v<=n;v++){
                int temp=d[u]+G[u][v];
                if(temp<d[v]){
                    d[v]=temp;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,d[i]);
        }
        cout<<ans;
        return ans;
    }
};