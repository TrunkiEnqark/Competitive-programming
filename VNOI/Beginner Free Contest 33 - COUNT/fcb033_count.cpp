#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = (int) 2e5 + 5;

int n, ans[N], id[N], vi[N];
set<int> s[N];
vector<vector<int> > g;

void dfs(int u) {
	vi[u] = 1;
	for(int v : g[u]) if(!vi[v]) {
		dfs(v);
		int pu = id[u], pv = id[v];
		if(s[pu].size() >= s[pv].size()) {
			for(set<int>::iterator it = s[pv].begin(); it != s[pv].end(); ++it) s[pu].insert(*it);
		} else {
			id[u] = id[v];
			for(set<int>::iterator it = s[pu].begin(); it != s[pu].end(); ++it) s[pv].insert(*it);
		}
		ans[u] = s[id[u]].size();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	g.resize(n+1);
	for(int u, v, i = 1; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int x, i = 1; i <= n; ++i) {
		cin >> x;
		ans[i] = 1;
		id[i] = i;
		s[i].insert(x);
		vi[i] = 0;
	}
	dfs(1);
	for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}