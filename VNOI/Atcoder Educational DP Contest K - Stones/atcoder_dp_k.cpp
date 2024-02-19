#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<bool> dp(k+1, false);
	vector<int> p(n);
	for(auto &i : p) cin >> i;

	fo(i, 1, k) 
		for(auto j : p) 
			if(i >= j && !dp[i - j]) dp[i] = true;

	cout << (dp[k] ? "First" : "Second");

	return 0;
}