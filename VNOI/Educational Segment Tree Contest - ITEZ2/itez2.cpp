#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 5;

int n, m;
ll st[N<<2];

void build(int id, int l, int r) {
	if(l > r) return;

	if(l == r) {
		st[id] = 0;
		return;
	}

	int mid = (l + r) >> 1;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	st[id] = st[id*2] + st[id*2+1];
}

void update(int id, int l, int r, int i, int v) {
	if(i < l || r < i || l > r) return;

	if(l == r) {
		st[id] = v;
		return;
	}

	int mid = (l + r) >> 1;
	update(id*2, l, mid, i, v);
	update(id*2+1, mid+1, r, i, v);

	st[id] = st[id*2] + st[id*2+1];
}

ll get(int id, int l, int r, int u, int v) {
	if(v < l || r < u || l > r) {
		return 0;
	}

	if(u <= l && r <= v) {
		return st[id];
	}

	int mid = (l + r) >> 1;
	return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	build(1, 1, n);
	while(m--) {
		int c, x, y;
		cin >> c >> x >> y;
		if(c == 1) update(1, 1, n, x, y);
			else cout << get(1, 1, n, x, y) << '\n';
	}
}