#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator1) {
        string s="";
        long long numerator=numerator1,denominator=denominator1;
        if(numerator<0 ^ denominator<0) s.push_back('-');
        numerator=abs(numerator);
        denominator=abs(denominator);
        cout<<numerator<<" "<<denominator<<endl;
        long long v=numerator/denominator;
        long long k=numerator%denominator;
        char c[10];
        itoa(v,c,10);
        s+=string(c);
        if(k!=0) s.push_back('.');
        bool seen[10];
        int ind[10];
        for(int i=0;i<10;i++) {
            seen[i]=false;
            ind[i]=-1;
        }
        while(k!=0) {
            long long z=(k*10)/denominator;
            long long k1=(k*10)%denominator;
            if(seen[z]) {
                cout<<z<<" "<<ind[z]<<endl;
                s.insert(ind[z]-1,"(");
                s.push_back(')');
                break;
            }
            s.push_back((char)(z+48));
            k=k1;
            ////cout<<"k="<<k<<endl;
            //cout<<z<<" "<<s.length()<<endl;
            ind[z]=s.length();
            seen[z]=true;
        }
        return s;
    }
};
int main() {
    Solution s;
    int t;
    cin>>t;
    while(t--) {
    int a,b;
    //scanf("%d%d",&a,&b);
    a=-2147483648;
    b=-10;
    cout<<s.fractionToDecimal(a,b)<"\n";
    }
    return 0;
}
