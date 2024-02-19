#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

map<ii, int> m1, m2;
int x[31], y[31], a = 0, b = 0, u, v;

void back(map<ii, int> &m, int l, int r) {
	if(l == r) ++m[ii(a, b)];
	else {
		for(int k = 0; k < 2; ++k) {
			a += k * x[l]; b += k * y[l];
			back(m, l+1, r);
			a -= k * x[l]; b -= k * y[l];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	cin >> u >> v;

	back(m1, 0, n/2);
	back(m2, n/2, n);

	ll ans = 0;
	for(auto it : m1) {
		ii f = ii(u - it.fi.fi, v - it.fi.se);
		if(m2.count(f)) ans += (ll) m2[f] * it.se;
	}
	cout << ans;
}