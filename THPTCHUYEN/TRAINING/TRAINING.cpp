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

const int N = 1e5 + 5;

int a[N], b[N];
ll d[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	int n, c, k;
	cin >> n >> c >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

	for(int i = 1; i <= n; ++i) {
		if(b[i]) d[i] = (max(0, k - a[i]) + b[i] - 1) / b[i]; 
			else d[i] = (a[i] >= k ? 0 : 2e9);
	}

	sort(d+1, d+n+1);
	for(int i = 1; i <= n; ++i) d[i] += d[i-1];
	for(int i = n; i > 0; --i) if(d[i] <= c) {
		cout << i;
		return 0;
	}
}

//http://thptchuyen.ntucoder.net/Problem/Details/