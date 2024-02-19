#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

const int N = 30005;
const int INF = 0x3f3f3f3f;

int n, m;
vector<vector<ii> > g;
ll d1[N], d2[N], c1[N], c2[N];
vector<int> res;

void enter() {
	cin >> n >> m;
	g.resize(n);
	while(m--) {
		int u, v, c; cin >> u >> v >> c, --u, --v;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
}

void dijkstra(vector<vector<ii> > g, int s, ll *d, ll *c) {
	fill(d, d+n, +INF);
	d[s] = 0;
	c[s] = 1;
	priority_queue<ii, vector<ii>, greater<ii> > qu;
	qu.push({0, s});
	while(!qu.empty()) {
		int u = qu.top().se, du = qu.top().fi; qu.pop();
		if(du != d[u]) continue;
		for(auto x:g[u]) {
			int v = x.fi, l = x.se;
			if(d[v] > du + l) {
				c[v] = c[u];
				qu.push({d[v] = du + l, v});
			} else if(d[v] == du + l) c[v] += c[u];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	enter();
	dijkstra(g, 0, d1, c1);
	dijkstra(g, n-1, d2, c2);

	for(int i = 0; i < n; ++i) {
		if(!(d1[i] + d2[i] == d1[n-1] && c1[i]*c2[i] == c1[n-1])) res.push_back(i+1);
	}
	cout << res.size() << '\n';
	for(auto x:res) cout << x << '\n';

	return 0;
}