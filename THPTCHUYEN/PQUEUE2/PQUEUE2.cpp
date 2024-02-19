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
	vector<int> a(n);
	for(auto &x:a) cin >> x;

	sort(all(a));
	for(auto x:a) cout << x << ' ';
	cout << endl;
	reverse(all(a));
	for(auto x:a) cout << x << ' ';

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9726