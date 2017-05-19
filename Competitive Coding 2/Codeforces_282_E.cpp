//http://codeforces.com/contest/282/problem/E
#include <bits/stdc++.h>
using namespace std;
#define bitsize 42
typedef unsigned long long ll;
struct node {
	node *z,*o;
	node() {
		z=NULL;
		o=NULL;
	}
};
class PTrie {
	public:
		node *head;
		PTrie() {
			head = new node();
		}
		void insert(ll num,node *root) {
			ll one = 1;
			ll sel = (one<<(bitsize-1));
			node *cur = this->head;
			for(int i=0;i<bitsize;i++) {
				ll a = sel & num;
				//(a==0) ? cout<<0<<" " : cout<<1<<" ";
				sel>>=1;
				if(a==0) {
					if(root!=NULL) {
						cur->o = root->o;
						root = root->z;
					}
					if(cur->z == NULL) cur->z = new node();
					cur = cur->z;
				} else {
					if(root!=NULL) {
						cur->z = root->z;
						root = root->o;
					}
					if(cur->o == NULL) cur->o = new node();
					cur = cur->o;
				}
			}
		}
		ll maxXor(ll k) {
			ll one = 1;
			ll sel = (one<<(bitsize-1));
			node *cur = this->head;
			ll ans=0;
			for(int i=0;i<bitsize;i++) {
				ll a = sel & k;
				if(a==0) {
					if(cur->o!=NULL) {
						ans = ans|sel;
						cur=cur->o;
					} else {
						cur=cur->z;
						ans = ans&(~sel);
					}
				} else {
					if(cur->z!=NULL) {
						ans = ans|sel;
						cur=cur->z;
					} else {
						cur=cur->o;
						ans = ans&(~sel);
					}
				}
				sel>>=1;
			}
			return ans;
		}
		ll minXor(ll k) {
			ll one=1;
			ll sel = (one<<(bitsize-1));
			node *cur = this->head;
			ll ans=0;
			for(int i=0;i<bitsize;i++) {
				ll a = sel & k;
				if(a==0) {
					if(cur->z!=NULL) {
						cur=cur->z;
						ans = ans&(~sel);
					} else {
						ans = ans|sel;
						cur=cur->o;
					}
				} else {
					if(cur->o!=NULL) {
						cur=cur->o;
						ans = ans&(~sel);
					} else {
						ans = ans|sel;
						cur=cur->z;
					}
				}
				sel>>=1;
			}
			return ans;
		}
};
void dfs(node *head,string s) {
	if(head==NULL) {
		return;
	}
	if(s.length()==bitsize) cout<<s<<endl;
	if(head->o != NULL) dfs(head->o,s+'1');
	if(head->z != NULL) dfs(head->z,s+'0');
}
int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	vector<ll> v,dp;
	ll N,k,a=0;
	cin>>N;
	vector<PTrie *> tt(N+1,NULL);
	tt[N]= new PTrie();
	tt[N]->insert(0,NULL);
	for(int i=0;i<N;i++) {
		cin>>k;
		v.push_back(k);
		a = a^k;
		dp.push_back(a);
	}
	a = 0;
	for(int i=N-1;i>=0;i--) {
	    tt[i] = new PTrie();
	    a = a^v[i];
	    tt[i]->insert(a,tt[i+1]->head);
	}
	ll mx = 0;
	for(int i=0;i<N-1;i++) {
	    mx = max(mx,tt[i+1]->maxXor(dp[i]));
	}
	mx = max(mx,tt[0]->maxXor(0));
	cout<<mx<<endl;
	return 0;
} 