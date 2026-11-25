#include <bits/stdc++.h>
using namespace std;

const int MaxSize = 100;

struct Sqlist{
    int data[MaxSize];
    int length;
};
//初始化顺序表
void InitList(Sqlist &Li){
    Li.length = 0;
}
//输入
void InputList(Sqlist &Li, int n){
    Li.length = 0;

    if (n < 0 || n > MaxSize){
        cout << "太大了";
        return;
    }
    for (int i = 0; i < n; i++){
        cin >> Li.data[i];
        Li.length++;
    }
}
//输出
void PrintList(const Sqlist &Li){
    for (int i = 0; i < Li.length; i++){
        cout << Li.data[i] << " ";
    }
}

//按值查找
int FindValue(const Sqlist &Li, int v){
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

//插入
void Insert(Sqlist &Li, int k, int e){
    if (Li.length >= MaxSize){
        cout << "插满了";
        return;
    }
    if(k > Li.length+1 || k < 1){
        cout << "不能插";
        return;
    }
    for (int i = Li.length; i >= k; i--){
        Li.data[i] = Li.data[i-1];
    }
    Li.data[k-1] = e;
    Li.length++;
}
//删除
void Delete(Sqlist &Li, int k){
    if (k < 1||k > Li.length){
        cout << "不能删";
        return;
    }
    for(int i = k-1; i < Li.length-1; i++){
        Li.data[i] = Li.data[i+1];
    }
    Li.length--;
} 
//主程序
int main(){
    Sqlist Li;
    InitList(Li);

    int n;
    cin >> n;

    InputList(Li, n);
    PrintList(Li);

    int v;
    cin >> v;
    cout << FindValue(Li, v) << '\n';

    int k, e;
    cin >> k >> e;
    Insert(Li, k, e);
    PrintList(Li);

    cin >> k;
    Delete(Li, k);
    PrintList(Li);
    
    return 0;
}