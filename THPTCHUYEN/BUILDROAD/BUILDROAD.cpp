#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

const int N = 1e5 + 5;

int n, m, res = 0, flag[N];
vector<int> g[N];

void dfs(int u) {
    flag[u] = 1;
    for(auto v : g[u]) {
        if(!flag[v]) dfs(v);
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    memset(flag, 0, sizeof(flag));
    for(int i = 1; i <= n; ++i) if(!flag[i]) {
        ++res;
        dfs(i);
    }
    cout << res - 1;
    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9879