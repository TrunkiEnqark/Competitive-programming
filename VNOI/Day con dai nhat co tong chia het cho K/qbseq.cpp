#include <bits/stdc++.h>

using namespace std;

const int oo = 100000000;

int n, k;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int a[1001];
	int s = 0;
	for(int i = 1; i <= n; ++i) cin >> a[i], s = (s + a[i]) % k;

	int f[1001][51];

	f[0][0] = 0;
	for(int i = 1; i < k; ++i) f[0][i] = oo;

	
	for(int i = 1; i <= n; ++i) 
		for(int j = 0; j < k; ++j) f[i][j] = min(f[i-1][j], f[i-1][(((j - a[i]) % k) + k) % k] + 1);
	cout << n - f[n][s%k];
}