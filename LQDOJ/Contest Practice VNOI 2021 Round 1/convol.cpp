#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long

using namespace std;

const int N = 5005;

int n; 
ll a[N], b[N], dp[N][N];

void pr() {
	memset(dp, 0, sizeof(dp));

	ll ans = LLONG_MIN;
	fo(i, 1, n) fo(j, 1, n) dp[i][j] = max(dp[i-1][j-1] + a[i]*b[j], a[i]*b[j]), ans = max(ans, dp[i][j]);
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	fo(i, 1, n) cin >> a[i];
	fo(j, 1, n) cin >> b[j];

	pr();

	return 0;
}