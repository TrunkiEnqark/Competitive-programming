#include <bits/stdc++.h>

using namespace std;

const int N = 50000;

vector<int> v;
int n, q;

struct Node {
	int mi, ma;
} st[4*N];

Node comb(Node l, Node r) {
	return {
		min(l.mi, r.mi),
		max(l.ma, r.ma)
	};
}

void build(int id, int l, int r) {
	if(l == r) { st[id].mi = st[id].ma = v[l]; return; }

	int mid = (l + r) >> 1;
	build(id<<1, l, mid);
	build((id<<1) + 1, mid+1, r);

	st[id] = comb(st[id<<1], st[(id<<1) + 1]);
}

int find_min(int id, int l, int r, int  u, int v) {
	if(v < l || u > r) return (int)1e6;
	if(u <= l && v >= r) return st[id].mi;
	int mid = (l + r) >> 1;
	return min(find_min(id<<1, l, mid, u, v), find_min((id<<1) + 1, mid+1, r, u, v));
}

int find_max(int id, int l, int r, int  u, int v) {
	if(v < l || u > r) return 0;
	if(u <= l && v >= r) return st[id].ma;
	int mid = (l + r) >> 1;
	return max(find_max(id<<1, l, mid, u, v), find_max((id<<1) + 1, mid+1, r, u, v));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("text.out", "w", stdout);
	cin >> n >> q; v.resize(n+1);
	for(int i = 1; i <= n; ++i) cin >> v[i];
	build(1,1,n);
	while(q--) {
		int l, r; cin >> l >> r;
		cout << find_max(1,1,n,l,r) - find_min(1,1,n,l,r) << endl;
	}
}