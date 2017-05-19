//https://www.codechef.com/MAY17/problems/GPD/
#include <bits/stdc++.h>
using namespace std;
#define bitsize 31
typedef unsigned int uint;
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
		void insert(uint num,node *root) {
			uint sel = (1<<(bitsize-1));
			node *cur = this->head;
			for(int i=0;i<bitsize;i++) {
				uint a = sel & num;
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
		uint maxXor(uint k) {
			uint sel = (1<<(bitsize-1));
			node *cur = this->head;
			uint ans=0;
			for(int i=0;i<bitsize;i++) {
				uint a = sel & k;
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
		uint minXor(uint k) {
			uint sel = (1<<(bitsize-1));
			node *cur = this->head;
			uint ans=0;
			for(int i=0;i<bitsize;i++) {
				uint a = sel & k;
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
	map<uint,PTrie *> mp;
	
	uint N,Q,u,v,k,t;
	scanf("%u%u",&N,&Q);
	scanf("%u%u",&u,&k);
	mp[u]=new PTrie();
	mp[u]->insert(k,NULL);
	for(int i=0;i<N-1;i++) {
		scanf("%u%u%u",&u,&v,&k);
		mp[u]=new PTrie();
		mp[u]->insert(k,mp[v]->head);
	}
	//dfs(mp[6]->head,"");
	uint last_answer = 0;
	while(Q--) {
		scanf("%u",&t);
		t=t^last_answer;
		if(t==0) {
			scanf("%u%u%u",&v,&u,&k);
			u^=last_answer;v^=last_answer;k^=last_answer;
			mp[u] = new PTrie();
			mp[u]->insert(k,mp[v]->head);
		} else {
			scanf("%u%u",&v,&k);
			v^=last_answer;k^=last_answer;
			uint mx = mp[v]->maxXor(k), mn = mp[v]->minXor(k);
			last_answer = mx^mn;
			cout<<mn<<" "<<mx<<endl;
		}
	}
	return 0;
} 