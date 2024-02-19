#include <bits/stdc++.h>
#define ii pair<int, int>
#define N 500
#define fo(i,a) for(int i = 0; i < a; ++i)
#define fi first
#define se second
#define pb push_back
#define oo (int)1e9

using namespace std;

int f, n, c, flavor[N], a[N][N];
vector<vector<ii> > g;

void enter() {
	cin >> n >> f >> c;
	g.resize(n);
	for(int i = 0; i < f; flavor[i++]--) scanf("%d", flavor+i);
	for(int u, v, k, i = 0; i < c; ++i) {
		scanf("%d%d%d", &u, &v, &k);
		g[--u].pb(ii(--v, k));
		g[v].pb(ii(u, k));
	}
}

void dijkstra(int s, int d[]) {
	fo(i,n) d[i] = oo;
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q; q.push(ii(0, s));
	while(!q.empty()) {
		int u = q.top().se, du = q.top().fi; q.pop();
		if(du > d[u]) continue;
		for(vector<ii>::iterator it = g[u].begin(); it != g[u].end(); ++it) {
			int l = it->se, v = it->fi;
			if(d[v] > du + l) q.push(ii(d[v] = du + l, v));
		}
	}
}

void pr() {
	fo(u,n) dijkstra(u, a[u]);
	int mn = INT_MAX, pos = 0;
	fo(i,n) {
		int total = 0;
		for(int j = 0; j < f; total += a[i][flavor[j++]]);
		if(total < mn) mn = total, pos = i;
	}
	printf("%d", pos+1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("bp.inp", "r", stdin);
	enter();
	pr();
}