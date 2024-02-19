#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> ans; ans.pb(1);
	for(int k = 2; (int)ans.size() < n; ++k) {
		int p = ans.back() / k + 1; 
		for(int i = p, j = 1; j <= k; ++i, ++j) ans.pb(k*i);
	}
	cout << ans[n-1];
}