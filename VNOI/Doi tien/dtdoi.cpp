#include <bits/stdc++.h>

using namespace std;

int n, s, dp[10005], a[105];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int bonus = 0;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a+n);
	if(s > 10000) {
		bonus = (s - 10000) / a[n-1];
		s -= bonus * a[n-1]; 
	}	
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= s; ++i) {
		dp[i] = INT_MAX;
		for(int j = 0; a[j] <= i && j < n; ++j) 
			dp[i] = min(dp[i], dp[i-a[j]] + 1);
	}

	cout << dp[s] + bonus;

	return 0;
}