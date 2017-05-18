#include<bits/stdc++.h>
using namespace std;
vector<int> v[7];
vector<pair<int,int> > ans;
void fillKmp(int *kmp,int b,int N) {
    int i,len=0;
    kmp[0]=0;
    i=1;
    while(i<N) {
        if(v[b][i]==v[b][len]) {
            len++;
            kmp[i]=len;
            i++;
        } else {
            if(len!=0) len=kmp[len-1];
            else {
                kmp[i]=0;
                i++;
            }
        }
    }
}
bool searchSubArr(int *ar,int *kmp,int b,int N) {
    int i=0,j=0;
    while(i<2*N) {
        if(ar[i]==v[b][j]) {
            i++;
            j++;
        }
        if(j==N) return true;
        else if(i<2*N && v[b][j]!=ar[i]) {
            if (j != 0)
                j = kmp[j-1];
            else
                i = i+1;
        }
    }
    return false;
}
bool check(int a,int b) {
    //logic to check one array is rotation of others
    int n=v[a].size();
    int *ar=new int[2*n];
    for(int i=0;i<n;i++) {
        ar[i]=v[a][i];
    }
    for(int i=n;i<2*n;i++) {
        ar[i]=ar[i-n];
    }
    //search array b in array a
    int *kmp=new int[n];
    fillKmp(kmp,b,n);
    //for(int i=0;i<n;i++) cout<<kmp[i]<<" "; cout<<endl;
    bool ans = searchSubArr(ar,kmp,b,n);
    free(ar);
    free(kmp);
    return ans;
}
int main() {
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<7;i++) {
        v[i].resize(n);
        for(int j=0;j<n;j++) {
            scanf("%d",&a);
            v[i][j]=a;
        }
    }
    for(int i=0;i<7;i++) {
        for(int j=i+1;j<7;j++) {
            if(check(i,j)) ans.push_back(make_pair(min(i,j),max(i,j)));
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
    return 0;
}
