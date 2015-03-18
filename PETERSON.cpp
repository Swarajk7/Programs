#include<bits/stdc++.h>
using namespace std;
int ar[10][5];
int main()
{
    for(int i=0;i<10;i++) {
        for(int j=0;j<5;j++) ar[i][j]=-1;
    }
    for(int i=0;i<5;i++) {
        ar[i][i]=i+5;
        //cout<<i<<" "<<(char)(i+65)<<" "<<i+5<<endl;
        int z=i+1;
        if(z>4) z=0;
        //cout<<i<<" "<<(char)(z+65)<<" "<<z<<endl;
        ar[i][z]=z;
        z=i-1;
        if(z<0) z=4;
        //cout<<i<<" "<<(char)(z+65)<<" "<<z<<endl;
        ar[i][z]=z;
    }
    for(int i=5;i<10;i++) {
        ar[i][i%5]=i-5;
        //cout<<i<<" "<<(char)((i%5)+65)<<" "<<ar[i][i%5]<<endl;
        int z=i+2;
        if(z>=10) z=z-5;
        ar[i][z%5]=z;
        //cout<<i<<" "<<(char)((z%5)+65)<<" "<<z<<endl;
        z++; if(z>=10) z=z-5;
        //cout<<i<<" "<<(char)((z%5)+65)<<" "<<z<<endl;
        ar[i][z%5]=z;
    }
    int t;
    scanf("%d",&t);
    while(t--) {
        string s;
        cin>>s;
        int start=s[0]-'A';
        vector<int> ans;
        ans.push_back(start);
        for(int i=1;i<s.length();i++) {
            int k=s[i]-'A';
            if(ar[start][k]==-1 || ar[start][k]==start) break;
            start=ar[start][k];
            ans.push_back(start);
        }
        bool flag=false;
        if(ans.size()==s.length()) flag=true;
        if(!flag) {
            start=s[0]-'A'+5;
            ans.clear();
            ans.push_back(start);
            for(int i=1;i<s.length();i++) {
                int k=s[i]-'A';
                //cout<<start<<" "<<k<<endl;
                if(ar[start][k]==-1 || ar[start][k]==start) break;
                start=ar[start][k];
                ans.push_back(start);
            }
            if(ans.size()==s.length()) flag=true;
        }
        if(flag) {
            for(int i=0;i<ans.size();i++) cout<<ans[i]; cout<<endl;
        } else {
            cout<<"-1\n";
        }
    }
    return 0;
}
