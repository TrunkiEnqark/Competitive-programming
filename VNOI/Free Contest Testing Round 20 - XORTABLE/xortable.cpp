#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int b[n+1][n+1];
	for(int i = 1; i <= n; ++i) cin >> b[1][i];
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j <= n; ++j) b[i][j] = b[1][i]^b[1][j];
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= n; ++j) cout << b[i][j] << " \n"[j == n];
	return 0;
}