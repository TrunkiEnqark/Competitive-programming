#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int seg[N<<2], add[N<<2], n, m;

void update(int id, int l, int r, int u, int v, int a, int b) {
	if(l > r || v < l || r < u) return;

	if(u <= l && r <= v) {
		int t = (id - l)*a + b;
		seg[id] = (seg[id] + t)%MOD;
		add[id] = (add[id] + t)%MOD;
		return;
	}

	int mid = (l + r) >> 1;
	update(id*2, l, mid, u, v, a, b);
	update(id*2+1, mid+1, r, u, v, a, b);

	seg[id] = ((long long) seg[id*2]%MOD + seg[id*2+1]%MOD)%MOD + add[id];
}

int query(int id, int l, int r, int u, int v) {
	if(l > r || v < l || r < u) return 0;

	if(u <= l && r <= v) return seg[id];

	int mid = (l + r) >> 1;
	return ((long long) ((long long) query(id, l, mid, u, v)%MOD + query(id, mid+1, r, u, v)%MOD) + add[id]%MOD)%MOD;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while(m--) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			update(1, 1, n, l, r, a, b);
		} else {
			int l, r; 
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}