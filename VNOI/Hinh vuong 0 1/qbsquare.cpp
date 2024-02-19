#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int dp[1001][1001], a[1001][1001];
	int res = 0;
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) {
			cin >> a[i][j]; dp[i][j] = 1;
			if(a[i][j] == a[i-1][j] && a[i-1][j] == a[i-1][j-1] && a[i-1][j-1] == a[i][j-1]) 
				res = max(res, dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1);
		}
	cout << res;
}