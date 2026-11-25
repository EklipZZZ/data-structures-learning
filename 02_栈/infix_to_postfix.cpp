#include <bits/stdc++.h>
using namespace std;
//优先级函数
int priority(string op){
    if(op == "+" || op == "-"){
        return 1;
    }
    if(op == "*" || op == "/"){
        return 2;
    }
    return 0;
}
//输入一个中缀表达式，输出后缀表达式
int main(){
    vector<string> tokens;
    //注意之间带空格，方便ss拆分输入
    string line;
    getline(cin, line);

    stringstream ss(line);

    string str;
    while(ss >> str){
        tokens.push_back(str);
    }

    stack<string> st;

    for(auto c : tokens){

        // 数字或者字母，直接输出
        if(c != "+" && c != "-" &&
           c != "*" && c != "/" &&
           c != "(" && c != ")"){
            cout << c << " ";
        }

        // 左括号直接入栈
        else if(c == "("){
            st.push(c);
        }

        // 右括号：一直弹到左括号
        else if(c == ")"){
            while(!st.empty() && st.top() != "("){
                cout << st.top() << " ";
                st.pop();
            }

            st.pop();   // 把 "(" 弹掉
        }

        // + - * /
        else{
            while(!st.empty() &&
                  st.top() != "(" &&
                  priority(st.top()) >= priority(c)){

                cout << st.top() << " ";
                st.pop();
            }

            st.push(c);
        }
    }

    // 最后把剩下的运算符全部弹出来
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}