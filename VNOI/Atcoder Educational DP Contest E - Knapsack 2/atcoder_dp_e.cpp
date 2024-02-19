#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<long long> dp;

bool minimize(long long &a, const long long &b) {
	return (a > b ? a = b, 1 : 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, W; cin >> n >> W;
	vector<int> v(n+1), w(n+1);

	for(int i = 0; i < n; ++i) cin >> w[i] >> v[i];

	dp.resize(N, 1e18);
	dp[0] = 0;
	for(int i = 0; i < n; ++i)
		for(int j = N-1; j >= 0; --j) {
			if(dp[j] + w[i] <= W) 
				minimize(dp[j + v[i]], dp[j] + w[i]);
			// minimize(dp[i+1][j], dp[i][j]);
		}

	for(int i = N-1; i >= 0; --i) if(dp[i] != 1e18) {
		cout << i;
		return 0;
	}
}