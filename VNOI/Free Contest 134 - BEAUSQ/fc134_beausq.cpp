#include <bits/stdc++.h>

#define fo(i, a, b)  for(int i = a; i <= b; ++i)
#define fod(i, a, b) for(int i = a; i >= b; --i)
#define rep(i, a) 	 for(int i = 0; i < a; ++i)
#define repd(i, a) 	 for(int i = a-1; i >= 0; --i)
#define all(a) 		 a.begin(), a.end()

#define ll long long
#define pb push_back

using namespace std;

const int N = 20005;
const string yno[2] = {"NO\n", "YES\n"};

int n;
ll seg[N<<2], a[N];

void update1(int id, int l, int r, int i, ll val) {
	if(i < l || r < i || l > r) return;

	if(l == r) {
		seg[id] = val;
		return;
	}

	int mid = (l + r) >> 1;
	update1(id*2, l, mid, i, val);
	update1(id*2+1, mid+1, r, i, val);

	seg[id] = seg[id*2] * seg[id*2+1];
}

void update2(int id, int l, int r, int i, ll val) {
	if(i < l || r < i || l > r) return;

	if(l == r) {
		seg[id] *= val;
		return;
	}

	int mid = (l + r) >> 1;
	update2(id*2, l, mid, i, val);
	update2(id*2+1, mid+1, r, i, val);

	seg[id] = seg[id*2] * seg[id*2+1];
}


ll get(int id, int l, int r, int u, int v) {
	if(v < l || r < u || l > r) {
		return 1;
	}

	if(u <= l && r <= v) {
		return seg[id];
	}

	int mid = (l + r) >> 1;
	return get(id*2, l, mid, u, v) * get(id*2+1, mid+1, r, u, v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		update1(1, 1, n, i, a[i]);
	}

	int m;
	cin >> m;
	while(m--) {
		int c;
		cin >> c;
		if(c == 1) {
			int l, r; cin >> l >> r;
			int s = get(1, 1, n, l, r);
			// cout << s << ' ';
			cout << yno[s == (ll) sqrt(s)*sqrt(s)];
		} else {
			int i, val; 
			cin >> i >> val;
			update2(1, 1, n, i, val);
		}
	}

	return 0;
}