#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll kWh_to_money(int money) {
	ll ans = 0;
	
	ans += (ll) (money >= 100 ? 100 : money) * 200;
	money -= 100;
	if(money <= 0) return ans;

	ans += (ll) (money >= 9900 ? 9900 : money)*300;
	money -= 9900;
	if(money <= 0) return ans;
	
	ans += (ll) (money >= 990000 ? 990000 : money)*500;
	money -= 990000;
	
	if(money <= 0) return ans;
	
	ans += (ll) money*700;

	if(money > 0) ans += (ll) (money)*700;
	return ans;
}

int money_to_kWh(ll k) {
	int ans = 0;
	if(k > 497990000) {
		ans += (k - 497990000) / 700;
		k = 497990000;
	}

	if(k > 2990000) {
		ans += (k - 2990000) / 500;
		k = 2990000;
	}

	if(k > 20000) {
		ans += (k - 20000) / 300;
		k = 20000;
	}

	ans += k/200;
	return ans; 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll x, y; cin >> x >> y;
	int S = money_to_kWh(x);
	int lo = 0, hi = money_to_kWh(x);
	while(lo <= hi) {
		int mid = (lo + hi) >> 1;
		ll c = kWh_to_money(S - mid) - kWh_to_money(mid);
		if(c == y) {
			cout << kWh_to_money(mid); 
			return 0;
		}		
		if(c < y) hi = mid - 1; else lo = mid + 1;
	}
}