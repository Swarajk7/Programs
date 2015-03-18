#include<bits/stdc++.h>
using namespace std;
char s[100005];
void proc() {
    int pre[100005];
    pre[0]=0;
    int len=0;
    for(int i=1;i<strlen(s);) {
        if(s[i]==s[len]) {
            pre[i]=++len; i++;
        } else {
            if(len==0) {pre[i]=0;i++;}
            else {len=pre[len-1];}
        }
    }
    //for(int i=0;i<strlen(s);i++) cout<<pre[i]<<" ";cout<<endl;
    int m=pre[strlen(s)-1];
    int v=strlen(s)-m;
    bool flag=true;
    if(strlen(s)%v!=0) flag=false;
    /*else {
        for(int i=v;i<strlen(s);i+=v) {
            for(int j=0;j<v;j++) {
                if(s[j]!=s[i+j]) flag=false;
            }
            if(!flag) break;
        }
    }*/
    if(flag) printf("%d\n",strlen(s)/v);
    else printf("%d\n",1);
}
int main()
{
    scanf("%s",s);
    while(strcmp(s,"*")!=0) {
        proc();
        scanf("%s",s);
    }
    return 0;
}
