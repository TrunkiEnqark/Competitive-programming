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

int calc(int n) {
	int ans = 0;
	for(; n > 0; n /= 10) ans += n%10;
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	// int a[55];
	// a[1] = 50;
	// for(int i = 1; i < 50; ++i) 
	// 	if(a[i] > 9) a[i+1] = calc(a[i]); else a[i+1] = a[i] * 2;

	int res[] = {5, 10, 1, 2, 4, 8, 16, 7, 14};
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		if(n == 1) cout << 50 << '\n';
		else cout << res[(n-2)%9] << '\n';
	}

	// for(int i = 1; i <= 30; ++i) cout << i << ' ' << a[i] << '\n';

	return 0;
}

// 5, 10, 1, 2, 4, 8, 16, 7, 14

//http://thptchuyen.ntucoder.net/Problem/Details/9958