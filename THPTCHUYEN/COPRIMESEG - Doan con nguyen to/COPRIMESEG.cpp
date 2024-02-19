#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

const int N = 1e5 + 5;

int n;
ll a[N], seg[N<<2];

void build(int id, int l, int r) {
	if(l > r) return;

	if(l == r) {
		seg[id] = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(id*2, l, mid);
	build(id*2 + 1, mid + 1, r);

	seg[id] = gcd(seg[id*2], seg[id*2 + 1]);
}

ll get(int id, int l, int r, int u, int v) {
	if(u > r || v < l || l > r) return 0;

	if(u <= l && v >= r) return seg[id];

	int mid = (l + r) >> 1;
	return gcd(get(id*2, l, mid, u, v), get(id*2 + 1, mid + 1, r, u, v));
}

int find(int l, int r) {
	int res = INT_MAX;

	int i = 1, j = 1;
	while(i <= n) {
		// j = n;
		while(j <= n && get(1, 1, n, i, j) != 1) ++j;

		if(j == n + 1) break;

		res = min(res, j - i + 1);

		++i;
		j = max(j, i);
	}

	return (res == INT_MAX ? -1 : res);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);
	cout << find(0, n + 1);

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10964