#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	int n[t+1], N = 0;
	for(int i = 1; i <= t; ++i) cin >> n[i], N = max(N, n[i]);

	int a[100000 + 5];
	a[0] = 0; a[1] = 1;
	for(int i = 1; i <= (N>>1); ++i) {
		a[2*i] = a[i];
		a[2*i+1] = a[i] + a[i+1];
	}

	int f[100000 + 5];
	f[1] = 1;
	for(int i = 2; i <= N; ++i) f[i] = max(f[i-1], a[i]);

	for(int i = 1; i <= t; ++i) cout << f[n[i]] << endl;
}