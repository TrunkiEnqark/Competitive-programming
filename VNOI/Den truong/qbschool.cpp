#include <bits/stdc++.h>

#define pb push_back
#define ii pair<int, int>
#define ll long long
#define il pair<int, ll>
#define fi first
#define se second
#define oo (ll)1e12

using namespace std;

int n, m; 
ll d[5005], f[5005];
vector<vector<ii> > g;

void enter() {
	cin >> n >> m;
	g.resize(n+1);
	for(int k, u, v, c, i = 0; i < m; ++i) {
		cin >> k >> u >> v >> c;
		g[u].pb(ii(v,c));  
		if(k == 2) g[v].pb(ii(u,c)); 
	}
}

void dijkstra() {
	priority_queue<il, vector<il>, greater<il> > qu;
	for(int i = 1; i <= n; ++i) d[i] = oo;
	d[1] = 0;
	f[1] = 1;
	qu.push(ii(1,0));
	while(!qu.empty()) {
		int u = qu.top().fi, du = qu.top().se; 
		qu.pop();
		if(d[u] < du) continue;
		for(auto it : g[u]) {
			int v = it.fi, l = it.se;
			if(d[v] < d[u] + l) continue;
			if(d[v] > d[u] + l) {
				d[v] = d[u] + l;
				f[v] = f[u];
				qu.push(ii(v, d[v]));
			} else f[v] += f[u];
		} 
	}
}

void solve() {
	dijkstra();
	cout << d[n] << ' ' << f[n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	enter();
	solve();
}