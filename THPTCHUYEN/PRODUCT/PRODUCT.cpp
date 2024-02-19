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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	int n; cin >> n;
	vector<ll> a(n), mar1(n+1, 0), mar2(n+1, LLONG_MAX);
	for(auto &i : a) cin >> i;

	if(n <= 1e4) {
		ll res = LLONG_MIN;

		for(int i = 0; i < n; ++i)
			for(int j = i+1; j < n; ++j) res = max(res, (ll) a[i] * a[j]);
		cout << res;

		return 0;
	}

	mar1[n] = LLONG_MIN;
	mar2[n] = LLONG_MAX;
	for(int i = n-1; i >= 0; --i) {
		if(a[i] > 0) mar1[i] = max(mar1[i+1], a[i]); else mar1[i] = mar1[i+1];
		if(a[i] < 0) mar2[i] = min(mar2[i+1], a[i]); else mar2[i] = mar2[i+1];
		// cout << mar2[i] << ' ';
	}

	ll res = LLONG_MIN;
	for(int i = 0; i < n; ++i) 
		res = max({res, (ll) a[i] * (mar1[i+1] == LLONG_MIN ? 0 : mar1[i+1]), (ll) a[i] * (mar2[i+1] == LLONG_MAX ? 0 : mar2[i+1])});
	
	// cout << '\n';
	cout << res;

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10969