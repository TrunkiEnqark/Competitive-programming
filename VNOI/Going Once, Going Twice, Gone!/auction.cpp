#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> a(m);
	for(int i = 0; i < m; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	
	int price = 0, ans;
	for(int i = 0; i < m; ++i) {
		int p = m - i;
		if(p > n) p = n;
		if(a[i] * p > price) {
			price = a[i]*p;
			ans = a[i];
		}
	}
	cout << ans << ' ' << price;
}