#include <bits/stdc++.h>

#define fo(i, a, b)  for(int i = a; i <= b; ++i)
#define fod(i, a, b) for(int i = a; i >= b; --i)
#define rep(i, a) 	 for(int i = 0; i < a; ++i)
#define repd(i, a) 	 for(int i = a-1; i >= 0; --i)
#define all(a) 		 a.begin(), a.end()

#define ll long long
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
const ll oo = 1e14;

ll seg[N<<2], a[N];

void update(int id, int l, int r, int i, ll val) {
	if(i < l || r < i || l > r) return;

	if(l == r) {
		seg[id] = val;
		return;
	}

	int mid = (l + r) >> 1;
	update(id*2, l, mid, i, val);
	update(id*2+1, mid+1, r, i, val);

	seg[id] = max(seg[id*2], seg[id*2+1]);
}

ll get(int id, int l, int r, int u, int v) {
	if(v < l || r < u || l > r) {
		return -oo;
	}

	if(u <= l && r <= v) {
		return seg[id];
	}

	int mid = (l + r) >> 1;
	return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k; 
	cin >> n >> k;
	
	for(int i = 1; i <= n; ++i) cin >> a[i];

	update(1, 1, n, 1, max(0ll, a[1]));
	for(int i = 2; i <= k; ++i) update(1, 1, n, i, max(0ll, get(1, 1, n, 1, i-1)) + a[i]);
	// ll res = LLONG_MIN;
	for(int i = k+1; i <= n; ++i) { 
		update(1, 1, n, i, get(1, 1, n, i-k, i-1) + a[i]);
	}
	cout << get(1, 1, n, 1, n);
	
	return 0;
}