#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

const int N = 2e5;

int n;
vector<int> a, h;
ll bit[N<<2];

void update(int m, ll val) {
	for(; m <= n; m += m&(-m)) bit[m] = max(bit[m], val);
}

ll query(int m) {
	ll res = 0;
	for(; m > 0; m -= m&(-m)) res = max(res, bit[m]);
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	h.resize(n);
	a.resize(n);

	for(auto &x:h) cin >> x;
	for(auto &x:a) cin >> x;

	for(int i = 0; i < n; ++i) 
		update(h[i], query(h[i] - 1) + a[i]);

	cout << query(n);
}