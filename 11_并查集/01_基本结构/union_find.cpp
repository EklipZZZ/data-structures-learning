#include <bits/stdc++.h>
using namespace std;

//根节点指向自己；但是如果不用h或者s存树的高度和大小，可以直接让根的p数组里面的值是负数（那他指向谁呢），数字部分表示高度/大小
//假设这里采用后一种方法
//初始化
void Initial(int n){
	for(int i = 0; i < n; i++){
		p[i] = -1;
}
//用递归更简单
int Find(int x){
if(p[x] < 0){
//返回的是根，不是秩
	return x;
}
//路径压缩 沿某个路径查找时边找边压缩
return p[x] = Find(p[x]);
}

void Union(int x, int y){
	int rootx = Find(x);
	int rooty = Find(y);
    if(rootx == rooty){
        return;
    }
//按秩合并（按大小、按高度）
	if (p[rootx] > p[rooty]){ //更小/更矮
	p[rootx] = rooty;
}else if(p[rooty] > p[rootx]){
	p[rooty] = rootx;
}else{
	p[rootx] = rooty;
	p[rooty]--;
}
}
int main(){
    int n = 5;

    Initial(n);

    vector<vector<int>> edges = {
        {0, 1},
        {1, 3},
        {2, 4}
    };
    //集吧
    for(auto edge : edges){
        Union(edge[0], edge[1]);
    }

    return 0;
}