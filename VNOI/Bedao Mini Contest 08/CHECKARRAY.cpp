#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for(auto &x:a) cin >> x;
	sort(a.begin(), a.end());
	int cnt = 0;
	for(int i = 1; i < n; ++i) if(abs(a[i] - a[i-1]) <= 1) ++cnt;
	if(n-cnt == 1) cout << "YES"; else cout << "NO";
}