#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n+1), dp(n+1, 0);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	dp[1] = 0; dp[2] = abs(a[1] - a[2]);
	for(int i = 3; i <= n; ++i) dp[i] = min(dp[i-1] + abs(a[i-1] - a[i]), dp[i-2] + abs(a[i-2] - a[i]));

	// for(int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i == n];
	cout << dp[n];
}