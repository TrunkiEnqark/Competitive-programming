#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 5;

int n, m;
ll st[N<<2], a[N];

void build(int id, int l, int r) {
	if(l > r) return;

	if(l == r) {
		st[id] = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	
	st[id] = min(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int i, ll v) {
	if(i < l || r < i || l > r) return;

	if(l == r) {
		st[id] = v;
		return;
	}

	int mid = (l + r) >> 1;
	update(id*2, l, mid, i, v);
	update(id*2+1, mid+1, r, i, v);

	st[id] = min(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v, int k) {
	if(v < l || r < u || l > r) {
		return LLONG_MAX;
	}

	if(u <= l && r <= v) {
		if(st[id] >= k) return st[id];
	}

	int mid = (l + r) >> 1;
	return min(get(id*2, l, mid, u, v, k), get(id*2+1, mid+1, r, u, v, k));
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
			int i; ll v;
			cin >> i >> v;
			update(1, 1, n, i, v);
		} else {
			int x, y, k; cin >> x >> y >> k;
			cout << get(1, 1, n, x, y, k) << '\n';
		}
	}
}