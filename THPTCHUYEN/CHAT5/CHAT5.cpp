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

int n, k, a[N];
 
bool ok(int d) {
	int cnt = 0;
	for(int i = 1; i <= n; ++i) cnt += a[i]/d;
	return cnt >= k;
}

int search(int lo, int hi) {
	int res = 0;
	while(lo <= hi) {
		int mid = (lo + hi) >> 1;
		if(ok(mid)) {
			res = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	cout << search(1, 1e9);

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/4630