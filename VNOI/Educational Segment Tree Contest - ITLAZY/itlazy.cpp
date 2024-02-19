#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 5;

int n, m;
ll st[N<<2], a[N], add[N<<2];

void build(int id, int l, int r) {
	if(l > r) return;

	if(l == r) {
		st[id] = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	
	st[id] = max(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int u, int v, ll val) {
	if(v < l || r < u || l > r) return;

	if(u <= l && r <= v) {
		add[id] += val;
		st[id] += val;
		return;
	}

	int mid = (l + r) >> 1;
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);

	st[id] = max(st[id*2], st[id*2+1]) + add[id];
}

ll get(int id, int l, int r, int u, int v) {
	if(v < l || r < u || l > r) {
		return LLONG_MIN;
	}

	if(u <= l && r <= v) {
		return st[id];
	}

	int mid = (l + r) >> 1;
	return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v)) + add[id];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);
	cin >> m;
	while(m--) {
		int c;
		cin >> c;
		if(c == 1) {
			int l, r; ll v;
			cin >> l >> r >> v;
			update(1, 1, n, l, r, v);
		} else {
			int x, y; cin >> x >> y;
			cout << get(1, 1, n, x, y) << '\n';
		}
	}
}