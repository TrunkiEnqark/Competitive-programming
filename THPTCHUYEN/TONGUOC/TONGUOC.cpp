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

vector<ll> calc(ll n) {
	// ll res = 0;
	if(n == 1) return {1};

	vector<ll> res = {1};
	for(ll i = 2; i*i <= n; ++i) 
		if(n%i == 0) {
			if(i == n/i) {
				// res += i;
				// cout << i << ' ';
				res.pb(i);
			}
			else {
				// res += (i + n/i);
				// cout << i << ' ' << n/i << ' ';
				res.pb(i);
				res.pb(n/i);
			}
		}

	res.pb(n);
	// cout << n << '\n';

	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	ll a, b;
	cin >> a >> b;
	vector<ll> x = calc(a);

	ll res = 0;
	for(auto i:x) if(b % (3*i) == 0) res += i;
	cout << res;

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10978