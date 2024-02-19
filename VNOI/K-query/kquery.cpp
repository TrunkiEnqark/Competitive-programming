#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first 
#define se second
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 30005, Q = 200005;

struct Query {
	int u, v, k, id;
	bool operator < (const Query &q) { return k < q.k; }
};

int ans[Q], m, n, bit[N];
ii a[N];
Query query[Q];

void enter() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		Query &q = query[i];
		cin >> q.u >> q.v >> q.k;
		q.id = i;
	}
}

void inc(int v) {
	for(; v <= n; v += v&-v) ++bit[v];
}

int sum(int v) {
	int res = 0;
	for(; v > 0; v -= v&-v) res += bit[v];
	return res;
}

void solve() {
	sort(a+1, a+n+1);
	sort(query+1, query+m+1);
	int pos = n;
	for(int i = m; i > 0; --i) {
		Query &q = query[i];
		while(a[pos].fi > q.k) {
			inc(a[pos--].se);
		}
		ans[q.id] = sum(q.v) - sum(q.u - 1);
	}
}

void print() {
	for(int i = 1; i <= m; ++i) cout << ans[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	enter();
	solve();
	print();
}