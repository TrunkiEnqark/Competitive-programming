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

vector<ll> a;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	int n; cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) a[i] = (ll) (i+1)*(i+1) + 1;

	int t; cin >> t;
	while(t--) {
		ll p;
		cin >> p;
		cout << *lower_bound(all(a), p) << '\n';
	}

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4607