#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
vector<ll> a, b;

ll search(ll x) {
	int l = 0, r = n-1;
	ll res = LLONG_MAX;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(b[mid] == -x) return 0ll;
		if((ll) -b[mid] <= x) {
			res = min(res, abs(x + b[mid]));
			r = mid - 1;
			// if(b[mid] < 0) l = mid + 1; else r = mid - 1;
		} else l = mid + 1;
	}
    if(abs(b[l] - x) < abs(b[r] - x)) return b[l]; 
	return b[r]; 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for(auto &x:a) cin >> x;
	for(auto &x:b) cin >> x;

	sort(b.begin(), b.end());

	ll res = LLONG_MAX;
	for(auto x:a) {
		ll k = search(x);
		if(k != LLONG_MAX) res = min(res, k);
	}
	cout << res;
}
