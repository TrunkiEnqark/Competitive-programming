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

const int N = 1e5 + 5;

int n, m, a[N], flag[N], cnt = -1;
ll res = 0, ans = LLONG_MAX;
vector<int> g[N], trace[N];

void enter() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	while(m--) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u) {
	flag[u] = 1;
	ans = min(ans, (ll) a[u]);
	for(auto v : g[u]) {
		if(!flag[v]) dfs(v);
	}
}

void solve() {
	memset(flag, 0, sizeof(flag));
	for(int i = 1; i <= n; ++i) {
		if(!flag[i]) {
			++cnt;
			ans = INT_MAX;
			dfs(i);
			res += ans;
		}
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	enter();
	solve();

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/6912