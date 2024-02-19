#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const ll Limit[] = {0, 59, 37, 25, 21, 17, 16, 14, 14, 13, 12};
const ll INF = (ll) 1e18;

ll dp[1005][11];
int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 11; ++j) {
			if(i == 1) dp[i][j] = 1;
				else if(j == 0) dp[i][j] = LLONG_MAX;
					else {
						dp[i][j] = dp[i][j-1];
						for(ll k = 1, tmp = prime[j]; k <= Limit[j]; ++k, tmp *= prime[j]) {
							if(i % (k+1) == 0 && dp[i/(k+1)][j-1] <= INF / tmp) {
								dp[i][j] = min(dp[i][j], dp[i/(k+1)][j-1] * tmp);
							}
						}
					}
		}
	cout << dp[n][10];
}
