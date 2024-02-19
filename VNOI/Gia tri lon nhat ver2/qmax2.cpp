#include <bits/stdc++.h>

#define ll long long
#define N 300005

using namespace std;

int st[N], add[N];

void build(int id, int l, int r, int u, int v, int k) {
	if(u > r || v < l || l > r) return;
	if(u <= l && r <= v) st[id] += k, add[id] += k; else {
		int mid = (l + r) >> 1;
		build((id<<1), l, mid, u, v, k);
		build((id<<1)+1, mid + 1, r, u, v, k);
		st[id] = max(st[id<<1], st[(id<<1) + 1]) + add[id];
	}
}

int query(int id, int l, int r, int u, int v) {
	if(u > r || v < l || l > r) return INT_MIN;
	if(u <= l && v >= r) return st[id];

	int mid = (l + r) >> 1;
	return max(query(id<<1, l, mid, u, v), query((id<<1) + 1, mid+1, r, u, v)) + add[id];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//memset(st, 0, sizeof(st));
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int ok; scanf("%d", &ok);
		if(ok == 0) {
			int u,v,k; scanf("%d%d%d", &u, &v, &k);
			build(1,1,n,u,v,k);
		} else {
			int u, v; scanf("%d%d", &u, &v);
			printf("%d\n", query(1,1,n,u,v));
		}
	}

	return 0;
}