#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int seg[4*MAX],ar[MAX];
int build(int index,int left,int right) {
    if(left==right) {
        seg[index]=ar[left];
        return seg[index];
    }
    int mid=(left+right)/2;
    int leftValue=build(2*index+1,left,mid);
    int rightValue=build(2*index+2,mid+1,right);
    seg[index]=min(leftValue,rightValue);
    return seg[index];
}
int findMin(int index,int left,int right,int ql,int qr) {
    if(left>qr || right<ql) return INT_MAX;
    if(left>=ql && qr>=right) {
        return seg[index];
    }
    int mid=(left+right)/2;
    int leftValue=findMin(2*index+1,left,mid,ql,qr);
    int rightValue=findMin(2*index+2,mid+1,right,ql,qr);
    return min(rightValue,leftValue);
}
int update(int index,int left,int right,int u_ind,int newval) {
    if(left>u_ind || right<u_ind) return INT_MAX;
    if(left==right) {
        ar[u_ind]=newval;
        seg[index]=newval;
        return seg[index];
    }
    int mid=(left+right)/2;
    int leftValue=update(2*index+1,left,mid,u_ind,newval);
    int rightValue=findMin(2*index+2,mid+1,right,u_ind,newval);
    seg[index]=min(rightValue,leftValue);
    return seg[index];
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>ar[i];
    }
    build(0,0,n-1);
    int q,ql,qr;
    cin>>q;
    update(0,0,n-1,0,-9);
    while(q--) {
        cin>>ql>>qr;
        cout<<findMin(0,0,n-1,ql,qr)<<"\n";
    }
    return 0;
}
