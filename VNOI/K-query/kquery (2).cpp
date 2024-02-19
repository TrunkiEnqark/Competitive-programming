#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()

using namespace std;

const int N = 200005;

vector<int> a, st[N];
int n, m;

void build(int id, int l, int r) {
	if(l > r) return;
	if(l == r) {
		st[id].push_back(a[l]);
		return;
	}
	int mid = (l + r) / 1;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	merge(all(st[id*2]), all(st[id*2+1]), st[id].begin());
}

int query(int id, int l, int r, int u, int v, int k) {
	if(l > r || l > v || r < u) return 0;
	if(l >= u && r <= v) 
		return ( st[id].size() - (upper_bound(all(st[id]), k) - st[id].begin()) );

	int mid = (l + r) / 2;
	return query(id*2, l, mid, u, v, k) + query(id*2+1, mid+1, r, u, v, k);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	a.resize(n+1);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);
	cin >> m;
	while(m--) {
		int x, y, k; cin >> x >> y >> k;
		cout << query(1, 1, n, x, y, k) << '\n'; 
	}
}