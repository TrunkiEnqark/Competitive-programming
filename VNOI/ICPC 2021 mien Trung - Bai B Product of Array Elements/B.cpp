#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = (ll) 1e9 + 7;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<ll> a(n);
	int vitriam = -1, vitri0 = -1, vt = -1, dau = 1;
	ll ma = LLONG_MIN;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] == 0) vitri0 = i;
		if(a[i] < 0 && a[i] > ma) ma = a[i], vitriam = i;
		if(a[i] < 0) dau *= -1;
	}

	if(dau == -1) vt = vitriam;
		else if(vitri0 != -1) vt = vitri0;

	ll res = 1ll;
	for(int i = 0; i < n; ++i) if(i != vt) res = ((ll) res*a[i])%MOD;
	cout << res;
}