#include <bits/stdc++.h>

#define ll long long
#define N 300005

using namespace std;

const int INF = 0x3f3f3f3f;

struct {
	int lazy, val;
} st[N];
int n, m;



void down(int id) {
	int t = st[id].lazy;

	st[id*2].val += t;
	st[id*2].lazy += t;

	st[id*2 + 1].val += t;
	st[id*2 + 1].lazy += t;

	st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
	if(l > r || v < l || u > r) return;
	if(l >= u && r <= v) {
		st[id].val += val;
		st[id].lazy += val;
		return;
	}

	down(id);

	int mid = (l + r) >> 1;
	update(id<<1, l, mid, u, v, val);
	update((id<<1)+1, mid+1, r, u, v, val);

	st[id].val = max(st[id<<1].val, st[(id<<1)+1].val);
}

int get(int id, int l, int r, int u, int v) {
	if(l > r || v < l || u > r) return -INF;
	if(l >= u && r <= v) return st[id].val;

	down(id);

	int mid = (l + r) >> 1;
	return max(get(id<<1, l, mid, u, v), get((id<<1)+1, mid+1, r, u, v));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while(m--) {
		int type; cin >> type;
		if(type == 0) {
			int x, y, k; cin >> x >> y >> k;
			update(1, 1, n, x, y, k);
		} else {
			int x, y; cin >> x >> y;
			cout << get(1, 1, n, x, y) << '\n';
		}
	}
	return 0;
}