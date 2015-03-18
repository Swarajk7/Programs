//http://codeforces.com/contest/346/status/page/5?order=BY_JUDGED_DESC

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pob pop_back
#define rs resize
#define as assign
#define fs first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define mp make_pair
#define sz(a) (int)a.size()
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FOD(i, n) for (int i = n - 1; i >= 0; --i)

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <string> vs;
typedef vector <vs> vvs;
typedef vector <char> vc;
typedef vector <vc> vvc;
typedef vector <vvc> vvvc;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvl> vvvl;
typedef vector <vvvl> vvvvl;
typedef vector <vvb> vvvb;
typedef double db;
typedef long double ldb;
typedef vector <db> vdb;
typedef vector <vdb> vvdb;
typedef vector <vvdb> vvvdb;
typedef vector <ldb> vldb;
typedef pair <int, int> ii;
typedef pair <int, char> ic;
typedef pair <ll, ll> lll;
typedef pair <int, ll> il;
typedef pair <ll, int> li;
typedef vector <ii> vii;
typedef vector <ic> vic;
typedef vector <vic> vvic;
typedef vector <vii> vvii;
typedef vector <lll> vll;
typedef vector <vll> vvll;
typedef set <int> si;
typedef set <ll> sl;
typedef set <pair <ll, int> > sli;
typedef set <pair <ll, ll> > sll;
typedef set <ii> sii;
typedef set <pair <int, bool> > sib;
typedef vector <si> vsi;
typedef vector <sii> vsii;
typedef map <int, int> mii;
typedef map <string, char> msc;
typedef map <char, int> mci;
typedef queue <int> qi;
typedef deque <int> di;
typedef stack <int> sti;

const int inf = (int)1e9 + 7;
const ldb eps = 1e-18;
const int N = 101;

struct pt
{
    int l, r, n;
    pt() { }
    pt(int l, int r, int n) : l(l), r(r), n(n) { }
};

int main()
{
    string s, t, p;
    cin >> s >> t >> p;
    int n = sz(s), m = sz(t), k = sz(p);
    vvvi dp(n + 1, vvi(m + 1, vi(k + 1, -1)));
    vvi kp(k, vi(26, 0));
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < 26; ++j)
            for (int x = 0; x <= i; ++x)
            {
                bool w = 1;
                for (int xx = 0; xx < x; ++xx)
                    if (p[xx] != p[i - x + xx])
                    {
                        w = 0;
                        break;
                    }
                if (w && p[x] == char('A' + j))
                    kp[i][j] = x + 1;
            }
    vector <vector <vector <pt> > > pr(n + 1, vector <vector <pt> > (m + 1, vector <pt> (k + 1, pt(-1, -1, -1))));
    dp[0][0][0] = 0;
    s += '&';
    t += '$';
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int q = 0; q < k; ++q)
            {
                if (dp[i][j][q] == -1)
                    continue;
                if (i < n && j < m && s[i] == t[j] && dp[i][j][q] + 1 > dp[i + 1][j + 1][kp[q][s[i] - 'A']])
                {
                    dp[i + 1][j + 1][kp[q][s[i] - 'A']] = dp[i][j][q] + 1;
                    pr[i + 1][j + 1][kp[q][s[i] - 'A']] = pt(i, j, q);
                }
                if (i < n && dp[i][j][q] > dp[i + 1][j][q])
                {
                    dp[i + 1][j][q] = dp[i][j][q];
                    pr[i + 1][j][q] = pt(i, j, q);
                }
                if (j < m && dp[i][j][q] > dp[i][j + 1][q])
                {
                    dp[i][j + 1][q] = dp[i][j][q];
                    pr[i][j + 1][q] = pt(i, j, q);
                }
            }
    int ans = 0, x = -1;
    for (int q = 0; q < k; ++q)
        if (ans < dp[n][m][q])
        {
            ans = dp[n][m][q];
            x = q;
        }
    if (ans == 0)
    {
        printf("0");
        return 0;
    }
    int y = n, z = m;
    string an = "";
    for (; x >= 0 && y > 0 && z > 0;)
    {
        int xx = pr[y][z][x].n;
        int yy = pr[y][z][x].l;
        int zz = pr[y][z][x].r;
        if (yy == y - 1 && zz == z - 1)
            an += s[y - 1];
        x = xx;
        y = yy;
        z = zz;
    }
    reverse(an.begin(), an.end());
    cout << an.size()<<endl;
    return 0;
}
