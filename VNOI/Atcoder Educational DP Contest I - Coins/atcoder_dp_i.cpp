#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<double> p(n+1);
	vector<vector<double> > dp(3005, vector<double> (3005, 0));
	fo(i, 1, n) cin >> p[i];
	int m = n/2 + 1;

	fo(i, 0, n) dp[i][0] = 1;

	fo(i, 1, n) fo(j, 1, m) dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1 - p[i]);
	cout << fixed << setprecision(10) << dp[n][m];

	return 0;
}