#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int sum_left[]  = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};
const int sum_right[] = {0, 45, 44, 42, 39, 35, 30, 24, 17, 9};

int cal(ll x) {
	int res = 0;
	while(x > 0) {
		res += x%10;
		x /= 10;
	}
	return res;
}

int calc(ll x) {
	int res = cal(x);
	while(res > 9) res = cal(res);
	return res;
}

void Process() {
	ll l, r; cin >> l >> r;
	if(r-l < 10) {
		int ans = 0;
		for(ll i = l; i <= r; ++i) ans += calc(i);
		cout << ans << '\n';
		return; 
	}

	int L = calc(l), R = calc(r);
	ll ans = sum_right[L] + sum_left[R];
	l += (ll) L;
	r -= (ll) R;
	int k = (r-l)/9;
	ans += (ll) (k+1)*45;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	// cout << calc(t);
	while(t--) Process();
	return 0;
}