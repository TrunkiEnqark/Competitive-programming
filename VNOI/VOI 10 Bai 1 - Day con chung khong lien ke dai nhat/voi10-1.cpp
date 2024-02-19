#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	vector<int> a(m+1), b(n+1);
	for(int i = 1; i <= m; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	int f[m+1][n+1];

	// f[0][0] = 0;
	// for(int i = 1; i <= m; ++i) f[i][1] = f[i-1][1] || (a[i] == b[1]);
	// for(int j = 1; j <= n; ++j) f[1][j] = f[1][j-1] || (a[1] == b[j]);

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j) {
			f[i][j] = max(f[i][j-1], f[i-1][j]);
			if(a[i] == b[j]) f[i][j] = f[i-2][j-2] + 1; 
		}	
	cout << f[m][n];
}