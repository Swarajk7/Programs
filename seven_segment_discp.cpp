#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
string s[10]={"1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011"};
vector<int> working_sol;
bool process(int assume,vector<string> v)
{
    int k=assume;
    int working[]={0,0,0,0,0,0,0};
    int counter=0;
    while(counter<v.size())
    {
        //v[counter] and s[k]
        for(int i=0;i<7;i++)
        {
            if(v[counter][i]=='1')
            {
                if(s[k][i]=='0') return false;
                else
                {
                    if(working[i]==1) return false;
                    working[i]=2;
                }
            }
            else
            {
                if(s[k][i]=='1')
                {
                    if(working[i]==2) return false;
                    working[i]=1;
                }
            }
        }
        k=(10+k-1)%10;
        counter++;
    }
    //v.clear();
    for(int i=0;i<7;i++)
    {
        working_sol.push_back(working[i]);
    }
    return true;
}
int main()
{
    int t,n;
    cin>>t;
    vector<string> v;
    for(int t1=1;t1<=t;t1++)
    {
        printf("Case #%d: ",t1);
        working_sol.clear();
        v.clear();
        cin>>n;
        v.resize(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int no_of_false=0,no_of_true=0;
        int ans=0;
        for(int assume=0;assume<=9;assume++)
        {
            bool got=process(assume,v);
            if(got) {
                no_of_true++;
                ans=assume;
            }
            else no_of_false++;
        }
        if(no_of_true==1)
        {
            /*cout<<ans<<endl;
            for(int i=0;i<working_sol.size();i++)
                printf("%d ",working_sol[i]);*/
            int final_ans=(10+ans-n)%10;
            for(int i=0;i<7;i++)
            {
                if(s[final_ans][i]=='0')
                {
                    cout<<0;
                }
                else
                {
                    if(working_sol[i]==2) cout<<1;
                    else cout<<0;
                }
            }
            cout<<endl;
        }
        else
        {
            printf("ERROR!\n");
        }
    }
    return 0;
}
