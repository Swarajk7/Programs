#include<bits/stdc++.h>
using namespace std;
bool searchS(int A[], int n, int target) {
        int left=0,right=n-1;
        while(left<=right) {
            int mid=(left+right)/2;
            if(A[mid]==target) return true;
            if(target>A[mid]) {
                if(target<A[right]) left=mid+1;
                else right=mid-1;
            } else {
                if(A[right]<target) right=mid-1;
                else left=mid+1;
            }
            //cout<<left<<" "<<right<<endl;
        }
        return false;
    }
int main() {
    int A[]={1,3};
    int target=3;
    cout<<searchS(A,sizeof(A)/sizeof(int),target);
}
