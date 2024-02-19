#include <bits/stdc++.h>

using namespace std;

bool maximize(long long &a, const long long &b) {
	return (a < b ? a = b, 1 : 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, W; cin >> n >> W;
	vector<int> v(n+1), w(n+1);

	for(int i = 0; i < n; ++i) cin >> w[i] >> v[i];

	vector<vector<long long> > dp(n+1, vector<long long> (W+1, 0));

	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= W; ++j) {
			if(j <= W - w[i]) 
				maximize(dp[i+1][j+w[i]], dp[i][j] + v[i]);
			maximize(dp[i+1][j], dp[i][j]);
		}

	cout << dp[n][W];
}