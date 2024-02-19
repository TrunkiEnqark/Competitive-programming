#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector<int> a(n+1), dp(n+1, 0);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	dp[1] = 0;
	for(int i = 2; i <= n; ++i) {
		dp[i] = INT_MAX;
		for(int j = 1; j <= k; ++j) 
			if(i > j) dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j])); 
	}

	// for(int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i == n];
	cout << dp[n];
}