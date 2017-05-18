#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector< vector<int> > v;
int main()
{
    int t,n,x;
    string str;
    scanf("%d",&t);
    for(int t1=1;t1<=t;t1++)
    {
        cin>>n>>str;
        v.resize(n);
        for(int i=0;i<n;i++) v[i].resize(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&x);
                v[i][j]=x;
            }
        }
        //cout<<str;
        if(str.compare("right")==0)
        {

            for(int i=0;i<n;i++)
            {
                for(int j=n-1;j>=0;j--)
                {
                    for(int k=j-1;k>=0;k--)
                    {
                        if(v[i][k]==0) continue;
                        else
                        {
                            if(v[i][k]==v[i][j])
                            {
                                v[i][j]+=v[i][k];
                                v[i][k]=0;
                                break;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                queue<int> q;
                for(int j=n-1;j>=0;j--)
                {
                    if(v[i][j]!=0) q.push(v[i][j]);
                }
                for(int j=n-1;j>=0;j--)
                {
                    if(!q.empty())
                    {
                        v[i][j]=q.front();
                        q.pop();
                    }
                    else v[i][j]=0;
                }
            }
        }
        else if(str.compare("left")==0)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(v[i][k]==0) continue;
                        else
                        {
                            if(v[i][k]==v[i][j])
                            {
                                v[i][j]+=v[i][k];
                                v[i][k]=0;
                                break;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                queue<int> q;
                for(int j=0;j<n;j++)
                {
                    if(v[i][j]!=0) q.push(v[i][j]);
                }
                for(int j=0;j<n;j++)
                {
                    if(!q.empty())
                    {
                        v[i][j]=q.front();
                        q.pop();
                    }
                    else v[i][j]=0;
                }
            }
        }
        else if(str.compare("up")==0)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(v[k][i]==0) continue;
                        else
                        {
                            if(v[k][i]==v[j][i])
                            {
                                v[j][i]+=v[k][i];
                                v[k][i]=0;
                                break;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                queue<int> q;
                for(int j=0;j<n;j++)
                {
                    if(v[j][i]!=0) q.push(v[j][i]);
                }
                for(int j=0;j<n;j++)
                {
                    if(!q.empty())
                    {
                        v[j][i]=q.front();
                        q.pop();
                    }
                    else v[j][i]=0;
                }
            }
        }

        else {
            for(int i=0;i<n;i++)
            {
                for(int j=n-1;j>=0;j--)
                {
                    for(int k=j-1;k>=0;k--)
                    {
                        if(v[k][i]==0) continue;
                        else
                        {
                            if(v[k][i]==v[j][i])
                            {
                                v[j][i]+=v[k][i];
                                v[k][i]=0;
                                break;
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
                queue<int> q;
                for(int j=n-1;j>=0;j--)
                {
                    if(v[j][i]!=0) q.push(v[j][i]);
                }
                for(int j=n-1;j>=0;j--)
                {
                    if(!q.empty())
                    {
                        v[j][i]=q.front();
                        q.pop();
                    }
                    else v[j][i]=0;
                }
            }
        }
        printf("Case #%d:\n",t1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<v[i][j]<< " ";
            }
            cout<<endl;
        }
    }
    return 0;
}
