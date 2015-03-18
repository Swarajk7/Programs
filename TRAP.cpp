#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> stk;
    bool flag=true;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='{' || s[i]=='(') stk.push(s[i]);
        else {
            if(s[i]=='}') {
                if(stk.empty() || stk.top()!='{') flag=false;
                else stk.pop();
            } else if(s[i]==')'){
                if(stk.empty() || stk.top()!='(') flag=false;
                else stk.pop();
            }
        }
        if(!flag) break;
    }
    if(!stk.empty()) flag=false;
    cout<<flag;
    return 0;
}
