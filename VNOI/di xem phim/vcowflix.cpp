#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL); cin.tie(0);
	int n, w; cin >> w >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	bool f[w+1];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(int i = 0; i < n; ++i) 
		for(int j = w; j >= v[i]; --j) f[j] = f[j] || f[j-v[i]];
	for(int i = w; i >= 0; --i) if(f[i]) { cout << i; return 0; } 
}