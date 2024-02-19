#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, k;
int a[305];
long long dp[305][305][155];

int calc(int l, int r) {
	return abs(a[l] - a[r]);
}

long long calc(int l, int r, int k) {
	if(k == 0) return 0;
	if(l > r) {
		return LLONG_MIN;
	}

	long long &res = dp[l][r][k];
	if(res != -1) return res;
	res = max(calc(l + 1, r, k), calc(l, r - 1, k));
	if(l < r) {
		res = max(res, calc(l + 2, r, k - 1) + calc(l, l + 1));
		res = max(res, calc(l, r - 2, k - 1) + calc(r, r - 1));
		res = max(res, calc(l + 1, r - 1, k - 1) + calc(l, r));
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	memset(dp, 255, sizeof(dp));

	cout << calc(1, n, k);
}