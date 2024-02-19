#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int INF = 0x3f3f3f3f;

struct pack {
	int u, v, c;
};

vector<pack> sync;
vector<vector<ii> > g;
int n, m, s, t, k;

bool cmp(const pack &a, const pack &b) { return a.c > b.c; }

void enter() {
	cin >> n >> m >> k >> s >> t;
	g.resize(n+1);
	for(int tmp = 1; tmp <= m; ++tmp) {
		int u, v, c; cin >> u >> v >> c;
		sync.pb({u, v, c});
		g[u].pb(ii(c, v));
		// g[v].pb(ii(c, u));
	}
}

int dijkstra() {
	vector<int> d(n+1, +INF);
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > qu;
	qu.push(ii(0, s));
	while(!qu.empty()) {
		int u = qu.top().se, du = qu.top().fi; qu.pop();
		if(d[u] != du) continue;
		for(auto V : g[u]) {
			int v = V.se, uv = V.fi;
			if(d[v] > du + uv) qu.push(ii(d[v] = du + uv, v));
		}
	}
	return d[t];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("test.in", "r", stdin);
	enter();
	sort(sync.begin(), sync.end(), cmp);
	for(int i = 0; i < k; ++i) {
		int u = sync[i].u, v = sync[i].v, c = sync[i].c;
		for(auto &x : g[u]) if(x.fi == c) x.fi = 0;
		// for(auto &x : g[v]) if(x.fi == c) x.fi = 0; 
	}
	cout << dijkstra();

	// cout << ans;
}