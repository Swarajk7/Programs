#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int left=0,right=n-1;
        while(left<right) {
            while(left<n && A[left]<=0) left++;
            while(right>=0 && A[right]>0) right--;
            //cout<<left<<" "<<right<<endl;
            if(left<right) {
                int k=A[left];
                A[left]=A[right];
                A[right]=k;
            }
        }
        int new_left=-1;
        for(int i=0;i<n;i++) {
            if(A[i]>0) {
                new_left=i;
                break;
            }
        }
        if(new_left==-1) return 1;
        for(int i=new_left;i<n;i++) {
            int k=abs(A[i])-1+new_left;
            if(k<n) {
                if(A[k]>0)
                A[k]=-1*A[k];
            }
        }
        for(int i=new_left;i<n;i++) {
            if(A[i]>0) return i-new_left+1;
        }
        return n-new_left+1;
    }
};
int main() {
    int A[]={1,0};
    Solution s;
    std::cout<<s.firstMissingPositive(A,sizeof (A) / sizeof(int));
    return 0;
}
