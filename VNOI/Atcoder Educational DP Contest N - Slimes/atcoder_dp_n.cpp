#include <bits/stdc++.h>

#define fo(i, a, b)  for(int i = a; i <= b; ++i)
#define fod(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;

const int mx = 405;
const ll INF = LLONG_MAX;

int n;
ll dp[mx][mx], a[mx], s[mx];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	fo(i, 1, n) cin >> a[i];

	s[0] = 0;
	fo(i, 1, n) s[i] = s[i-1] + a[i];

	memset(dp, 0x3f, sizeof(dp));

	fo(i, 1, n-1) dp[i][i+1] = a[i] + a[i+1];

	fo(i, 1, n) dp[i][i] = 0;
	
	fod(i, n, 1) fo(j, i + 1, n) {
		ll rs = INF;
		fo(k, i, j-1) rs = min(rs, dp[i][k] + dp[k+1][j]);
		dp[i][j] = rs + s[j] - s[i-1];
	}
	cout << dp[1][n];

	return 0;
}