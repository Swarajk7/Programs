#include<bits/stdc++.h>
using namespace std;
int hp[100005];
class MaxHeap {
    int cnt;
public:
    MaxHeap() { cnt=0;  }
    void push(int k) {
        hp[cnt]=k;
        int i=cnt;
        while(i!=0) {
            if(hp[i]>hp[(i-1)/2]) {
                int t=hp[i];
                hp[i]=hp[(i-1)/2];
                hp[(i-1)/2]=t;
                i=(i-1)/2;
            } else {
                break;
            }
        }
        cnt++;
    }
    int getMax() {
        return hp[0];
    }
    void pop() {
        if(cnt==0) throw exception();
        hp[0]=hp[cnt-1];
        cnt--;
        int i=0;
        while(i<cnt) {
            if(2*i+2<cnt) {
                if(hp[2*i+1]>hp[2*i+2]) {
                    if(hp[2*i+1]>hp[i]) {
                        int t=hp[2*i+1];
                        hp[2*i+1]=hp[i];
                        hp[i]=t;
                        i=2*i+1;
                    } else break;
                } else {
                    if(hp[2*i+2]>hp[i]) {
                        int t=hp[2*i+2];
                        hp[2*i+2]=hp[i];
                        hp[i]=t;
                        i=2*i+2;
                    } else break;
                }
            } else if(2*i+1<cnt) {
                if(hp[2*i+1]>hp[i]) {
                        int t=hp[2*i+1];
                        hp[2*i+1]=hp[i];
                        hp[i]=t;
                        i=2*i+1;
                } else break;
            } else break;
        }
    }
    bool empty() {
        return cnt==0;
    }
};
pair<int,int> p[10005];
bool cmp(pair<int,int> p1,pair<int,int> p2) {
    return p1.first>p2.first;
}
int main()
{
    int t,n,l,p1,a,b;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d%d",&a,&b);
            p[i]=make_pair(a,b);
        }
        scanf("%d%d",&l,&p1);
        sort(p,p+n,cmp);
        MaxHeap mh;
        bool flag=true;
        int ans=0;
        for(int i=0;i<n;i++) {
            //cout<<l<<" "<<p[i].first<<endl;
            int cost=l-p[i].first;
            p1-=cost;
            l=p[i].first;
            while(p1<0) {
                if(mh.empty()) {
                    flag=false;
                    break;
                } else {
                    p1+=mh.getMax();
                    mh.pop();
                    ans++;
                }
            }
            if(!flag) break;
            mh.push(p[i].second);
        }
        int cost=l;
        p1-=cost;
        while(p1<0) {
            if(mh.empty()) {
                flag=false;
                break;
            } else {
                p1+=mh.getMax();
                mh.pop();
                ans++;
            }
        }
        if(flag) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
