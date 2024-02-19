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

int n, m, level[N], par[N][21];
vector<int> g[N];

void dfs(int u) {
    for(int v : g[u]) {
        if(v == par[u][0]) continue;
        level[v] = level[u] + 1;

        par[v][0] = u;
        for(int j = 1; j <= 20; ++j) par[v][j] = par[par[v][j - 1]][j - 1];

        dfs(v);
    }
}

ILTQ {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    for(int i = 1; i <= n; ++i) par[i][0] = i;

    return 0;
}

// coded by Eula_simp_lord a.k.a I_Love_Truc_Quynh