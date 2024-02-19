#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> L(n+1, 0);
	L[0] = 1;
	for(int v = 1; v <= n; ++v) 
		for(int m = v; m <= n; ++m) L[m] = (L[m] + L[m-v])%MOD;
	cout << L[n]%MOD;
}