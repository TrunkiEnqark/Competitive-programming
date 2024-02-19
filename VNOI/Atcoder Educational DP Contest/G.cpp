#include <bits/stdc++.h>

#define NAME        ""

#define ILTQ				 	int main()
#define ll          			long long
#define ii         		  		pair<int, int>
#define ld          			long double
#define fi          			first
#define se          			second
#define endl        			'\n'
#define pb          			push_back

#define OK          			cout << "ok\n";
#define all(a)      			a.begin(), a.end()
#define rall(a)     			a.rbegin(), a.rend()

using namespace std;

const int MOD = 1e9 + 7;
const int base = 29;
const int N = 1e5 + 5;

int n, m, dp[N], vst[N];
vector<int> g[N];

int dfs(int u) {
    if(dp[u]) return dp[u];
    for(auto v : g[u]) {
        dp[v] = dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
    return dp[u];
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for(int u, v; m--; ) {
        cin >> u >> v;
        g[u].pb(v);
    }

    for(int i = 1; i <= n; ++i) {
        // memset(vst, 0, sizeof vst);
        dfs(i);
    }

    // for(int i = 1; i <= n; ++i) cout << dp[i] << ' ';
    cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh