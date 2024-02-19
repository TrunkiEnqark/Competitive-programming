#include <bits/stdc++.h>

#define ll unsigned long long
#define fo(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll f[65][65];
	fo(i, 1, 64) f[1][i] = 1;
	fo(i, 2, 64) f[i][3] = f[i-1][3]*2 + 1;
	fo(i, 2, 64) 
		fo(j, 4, 64) {
			if(i < j) f[i][j] = i*2 - 1;
				else {
					f[i][j] = f[i][j-1];
					fo(k, 1, i-1) f[i][j] = min(f[i][j], f[i-k][j-1] + f[k][j]*2);
				}
		}
	int m, n;
	while(cin >> n >> m) cout << f[n][m] << '\n';
}