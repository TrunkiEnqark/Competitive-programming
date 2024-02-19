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

	// int f[100];
	// f[0] = 0;
	// f[1] = 1;
	// for(int i = 2; i <= 20; ++i) f[i] = 2*f[i-1] - f[i-2] + 1;
	// for(int i = 0; i <= 20; ++i) cout << f[i] << ' '; 

	int t; cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << ((ll) ((n+1)%10)*((n+1)%10))%10 << '\n';
	}

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/10972