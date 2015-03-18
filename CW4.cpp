#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    return (n <= 1)? 1 :n * fact(n-1);
}
int findSmallerInRight(char* str, int low, int high)
{
    int countRight = 0, i;

    for (i = low+1; i <= high; ++i)
        if (str[i] < str[low])
            ++countRight;

    return countRight;
}
int findRank (char* str)
{
    int len = strlen(str);
    int mul = fact(len);
    int rank = 1;
    int countRight;

    int i;
    for (i = 0; i < len; ++i)
    {
        mul /= len - i;

        // count number of chars smaller than str[i]
        // fron str[i+1] to str[len-1]
        countRight = findSmallerInRight(str, i, len-1);

        rank += countRight * mul ;
    }

    return rank;
}

string proc(int x) {
    string s;
    if(x>=702) {
        x-=702;
        int p=x/26;
        s.push_back((char)(65+p));
    }
    if(x>=26) {
        x-=26;
        int p=x/26;
        s.push_back((char)(65+p));
    }
    if(x>=0) {
        x%=26;
        s.push_back((char)(65+x-1));
    }
    return s;
}

// Driver program to test above function
int main()
{
    int t;
    cin>>t;
    char s[20];
    while(t--) {
        cin>>s;
        int x=findRank(s);
        x=fact(strlen(s))-x+1;
        cout<<proc(x)<<endl;
    }
    return 0;
}
