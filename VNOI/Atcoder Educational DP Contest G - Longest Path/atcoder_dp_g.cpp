#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5+5;

int n, m;
vector<vector<int> > g;
vector<int> dp;

void enter() {
	cin >> n >> m;
	g.resize(n+1);
	dp.resize(n+1, 0);
	// f.resize(n+1, true);
	while(m--) {
		int u, v; cin >> u >> v;
		g[--u].push_back(--v);
	}
}

int dfs(int u) {
	// if(u == n) return cnt;
	if(dp[u]) return dp[u];

	for(auto v:g[u]) {
		dp[v] = dfs(v); 
		dp[u] = max(dp[u], dp[v]+1);
	}

	return dp[u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	enter();
	int res = -1;
	for(int i = 0; i < n; ++i)  
		res = max(res, dfs(i));
	
	cout << res; 
}