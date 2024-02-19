#include <bits/stdc++.h>
#define fo(i,a,b)  for(int i = a; i <= b; ++i)
#define fod(i,a,b) for(int i = a; i >= b; --i)
#define N 101
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

using namespace std;

const int oo = (int)1e6;

int n, m, k; 
int e[N][N], ans[N][N];

void floyd() {
	fo(u,1,n) fo(v,1,n) ans[u][v] = e[u][v];
	fo(k,1,n) fo(u,1,n) fo(v,1,n) ans[u][v] = min(ans[u][v], ans[u][k] + ans[k][v]);
}

void dijkstra(int uu, int vv) {
	int d[n+1], t[n+1];
	bool free[n+1];
	memset(free, 1, sizeof(free));
	fo(i,1,n) d[i] = oo; 
	d[uu] = 0;
	while(1) {
		int mi = INT_MAX, u = 0;
		fo(i,1,n) if(free[i] && d[i] < mi) mi = d[i], u = i;
		
		if(u == 0 || u == vv) break;

		free[u] = 0;
		fo(v,1,n) if(free[v] && d[u] + e[u][v] < d[v]) {
			d[v] = d[u] + e[u][v];
			t[v] = u;
		}
	}
	vector<int> res;
	while(vv != uu) {
		res.pb(vv);
		vv = t[vv];
	}
	res.pb(uu);
	reverse(res.begin(), res.end());
	cout << res.size() << ' ';
	for(auto x:res) cout << x << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
	//freopen("test.out", "w", stdout);
	cin >> n >> m >> k;
	fo(u,1,n) fo(v,1,n) e[u][v] = u == v ? 0 : oo;

	for(int u, v, c, i = 1; i <= m; ++i) {
		cin >> u >> v >> c;
		e[u][v] = e[v][u] = c;
	}

	floyd();

	while(k--) {
		bool x; 
		int u, v; 
		cin >> x >> u >> v;
		if(!x) cout << ans[u][v] << endl; 
		else dijkstra(u, v);
	}
}