#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int f[101];
	f[0] = 1; f[1] = 1;
	for(int i = 2; i <= 100; ++i) f[i] = (f[i-1] + f[i-2])%7; 	

	int t; cin >> t;
	while(t--) {
		int u, v; cin >> u >> v;
		int l = v - u + 1, ans = -1;
		if(l >= 32) ans = l/16*16; 
		else {
			u %= 32;
			for(int i = u; i < u + l - 1; ++i) if(f[i] == f[i+1]) ans = 2;
		}
		cout << ans << '\n';
	}
}