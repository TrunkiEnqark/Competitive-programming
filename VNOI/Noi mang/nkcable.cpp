#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 1; i < n; ++i) cin >> a[i];
	vector<int> dp(n+1);
	dp[1] = 0;
	dp[2] = a[1];
	dp[3] = a[1] + a[2];
	for(int i = 4; i <= n; ++i) dp[i] = a[i-1] + min(dp[i-1], dp[i-2]);
	cout << dp[n];
}