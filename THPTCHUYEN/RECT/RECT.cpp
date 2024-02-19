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

const ll MOD = 1000000007;
const int N = 3e5 + 5;

ll fact[N];

void init() {
	fact[1] = 1;
	for(int i = 2; i < N; ++i) fact[i] = (fact[i-1] * i) % MOD;
}

ll POW(ll a, ll n) {
	a %= MOD;
	ll ans = 1;
	while(n) {
		if(n&1) ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		n >>= 1;
	}
	return ans%MOD;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);
	init();

	// cout << POW(5, MOD-2)%MOD;

	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> m >> n;

		// cout << (fact[n + m]%MOD / (fact[n] * fact[m])%MOD) << '\n';

		cout << ((fact[n + m]%MOD) * (POW(fact[n] * fact[m], MOD - 2)%MOD))%MOD << '\n';
	}

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10973