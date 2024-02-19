#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define MOD 1000000007

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<vector<int> > a(n+1, vector<int> (m+1, 0));
	vector<vector<long long> > dp(n+1, vector<long long> (m+1, 0));
	fo(i, 1, n) fo(j, 1, m) {
		char c; cin >> c;
		a[i][j] = (c == '.');
	}

	// fo(i, 1, n) fo(j, 1, m) cout << a[i][j] << " \n"[j == m]; 

	dp[1][1] = 1;
	// fo(i, 2, n) if(a[i][1]) dp[i][1] = 1;
	// fo(j, 2, m) if(a[1][j]) dp[1][j] = 1;

	fo(i, 1, n) fo(j, 1, m) {
		if(a[i][j]) {
			if(i > 1) dp[i][j] += dp[i-1][j];
			if(j > 1) dp[i][j] += dp[i][j-1];
			dp[i][j] %= MOD;
			// dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
		} else dp[i][j] = 0;
	}
	// cout << '\n';
	// fo(i, 1, n) fo(j, 1, m) cout << dp[i][j] << " \n"[j == m]; 

	cout << dp[n][m];

	return 0;
}