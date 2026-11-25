#include <bits/stdc++.h>
using namespace std;

const int MaxSize = 100;

struct Sqlist{
    int data[MaxSize];
    int length;
};
//按值查找（按位序太简单跳过）
int FindValue(Sqlist &Li, int v){
    int i = 0;
    while(i < Li.length){
        if(Li.data[i] == v){
            //返回位序
            return i + 1;
        }
        i++;
    }
    return -1;
}
int main(){
    //创建
    Sqlist Li;
    Li.length = 0;
    int n;
    cin >> n;
    //输入
    for (int i = 0; i < n; i++){
        cin >> Li.data[i];
        Li.length++;
    }
    //输出
    for (int i = 0; i < Li.length; i++){
        cout << Li.data[i] << " ";
    }

    //插入在第k个位置
    int k, e;
    cin >> k >> e;
    if(k > Li.length+1 || k < 1){
        cout << "不能插";
        return 0;
    }
    for (int i = Li.length; i >= k; i--){
        Li.data[i] = Li.data[i-1];
    }
    Li.length++;
    Li.data[k-1] = e;
    //删掉第t个位置
    int t;
    cin >> t;
    if (t < 1||t > Li.length){
        cout << "不能删";
        return 0;
    }
    for(int i = t-1; i < Li.length-1; i++){
        Li.data[i] = Li.data[i+1];
    }
    Li.length--;


    return 0;
}
