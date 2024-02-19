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

int n;
vector<ll> a;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	cin >> n;
	a.resize(n);
	for(auto &x:a) cin >> x;
	sort(all(a));
	
	int t; cin >> t;
	while(t--) {
		ll p;
		cin >> p;
		vector<ll>::iterator it = upper_bound(all(a), p);
		--it;
		cout << *it << '\n';
	}

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4609