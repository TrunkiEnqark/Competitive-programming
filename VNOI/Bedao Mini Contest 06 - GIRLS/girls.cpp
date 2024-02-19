#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	ll a[n+1], sum[n+1];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	sum[0] = 0;
	for(int i = 1; i <= n; ++i) sum[i] = sum[i-1] + a[i];

	// for(int i = 1; i <= n; ++i) cout << sum[i] << " \n"[i==n];

	ll ans = LLONG_MIN;
	for(int l = 1; l <= n - m + 1; ++l) {
		int r = l + m - 1;
		if(abs(a[r] - a[l]) <= k) ans = max(ans, sum[r] - sum[l-1]);
	}
	cout << (ans == LLONG_MIN ? -2 : ans);

	return 0;
}