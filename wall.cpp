#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
double area(double x1,double y1,double x2,double y2,double x3,double y3) {
    double d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    double d3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    double s=(d1+d2+d3)/2;
    return sqrt(s*(s-d1)*(s-d2)*(s-d3));
}
int main() {
    int t;
    std::ios::sync_with_stdio(false);
    cin>>t;
    int h,n,m,a,b,ind;
    vector<int> d;
    vector<double> x,y;
    while(t--) {
        cin>>h;
        cin>>n>>m;
        cin>>a>>b>>ind;
        d.clear();
        x.clear();
        y.clear();
        d.resize(m);
        x.resize(n);
        y.resize(n);
        x[0]=0;y[0]=0;
        for(int i=0;i<m;i++) cin>>d[i];
        int i;
        for(i=1;i<n;i++) {
            x[i]=x[i-1]+d[ind];
            ind=(a*ind+b)%m;
            if(i%2==0) y[i]=0;
            else y[i]=h;
        }
        double total_area=0;
        for(int i=0;i<n-1;i++) {
            total_area+=(0.5*max(y[i],y[i+1])*(x[i+1]-x[i]));
        }
        printf("%.1llf\n",total_area);
    }
    return 0;
}
