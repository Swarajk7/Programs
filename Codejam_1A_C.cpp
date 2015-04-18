#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<pii> v;
pii pivot;
bool operator < (pii a,pii b) {
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}
int ccw(pii a, pii b, pii c) {
    int area = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}
ll sqrDist(pii a, pii b)  {
    ll dx = a.first - b.first, dy = a.second - b.second;
    return dx * dx + dy * dy;
}
bool POLAR_ORDER(pii a, pii b)  {
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

stack<pii> grahamScan(vector<pii> points, int N)    {
    stack<pii> hull;

    if (N < 3)
        return hull;

    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;

    // swap the pivot with the first point
    pii temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    // sort the remaining point according to polar order about the pivot
    pivot = points[0];
    sort(points.begin() + 1, points.begin() + N, POLAR_ORDER);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N; i++) {
        pii top = hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}


bool graham_scan(vector<pii> ar,pii p) {
    //cout<<"called\n";
    stack<pii> hull=grahamScan(ar,ar.size());
    while(!hull.empty()) {
        pii p1=hull.top();
        hull.pop();
        if(p1==p) return true;
    }
    return false;
}
int calc(int K) {
    //cout<<"A";
    int n=v.size();
    int ans=n+1;
    for(int i=0;i<(1<<n);i++) {
        //cout<<i<<endl;
        int j=i;
        int k=0;
        int del=0;
        vector<pii> v2;
        bool flag=false;
        while(j!=0) {
            if(j&1) v2.push_back(v[k]);
            if(k==K && (j&1)==1) flag=true;
            k++;
            if((j&1)==0) del++;
            j>>=1;
            //cout<<j<<endl;
        }
        if(flag) {
            if(graham_scan(v2,v[K])) {
                ans=min(ans,del);
            }
        }
    }
    return ans;
}
int main() {
    int t,n,a,b;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++) {
        int n;
        v.clear();
        scanf("%d",&n);
        while(n--) {
            scanf("%d%d",&a,&b);
            v.push_back(make_pair(a,b));
        }
        stack<pii> hull=grahamScan(v,v.size());
        while(!hull.empty()) {
            pii p1=hull.top();
            hull.pop();
            cout<<p1.first<<" "<<p1.second<<endl;
        }
        cout<<endl<<endl;
        n=v.size();
        for(int i=0;i<n;i++) {
            cout<<i<<" "<<calc(i)<<endl;
        }
    }
}
