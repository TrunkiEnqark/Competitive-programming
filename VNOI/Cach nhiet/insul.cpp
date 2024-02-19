#include <bits/stdc++.h>

#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);	
	int res = 0;
	for(int i = 0; i < n; ++i) cin >> a[i], res += a[i];
	sort(all(a));
	
	int tmp = 0;
	for(int i = 0; i < (n>>1); ++i) tmp += a[i];
	
	res += (res - tmp) - tmp - (n&1 ? a[n>>1] : 0);
	cout << res;

}