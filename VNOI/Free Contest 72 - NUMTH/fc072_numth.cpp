#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("txt.inp", "r", stdin);
	int k; cin >> k;
	int64_t d;
	vector<int64_t> a;
	while(cin >> d) a.push_back(d);
	sort(a.begin(), a.end(), greater<int64_t>());
	cout << a[k-1];
}