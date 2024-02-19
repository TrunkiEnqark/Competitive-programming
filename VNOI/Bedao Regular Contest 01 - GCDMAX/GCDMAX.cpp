#include <bits/stdc++.h>

#define gcd(a, b) __gcd(a, b)

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	if(n == 1) {
		int a; cin >> a;
		cout << a;
		return 0;
	}
	int a[n+1], suf[n+1], pre[n+1], mxArr = INT_MIN;
	for(int i = 1; i <= n; ++i) cin >> a[i], mxArr = max(mxArr, a[i]);

	suf[1] = mxArr; pre[n] = mxArr;
	for(int i = 2; i <= n; ++i) suf[i] = gcd(suf[i-1], a[i]);
	for(int i = n-1; i >= 1; --i) pre[i] = gcd(pre[i+1], a[i]);
	
	// suf[0] = pre[n+1] = 1;

	int res = 1;
	for(int i = 2; i < n; ++i) res = max(res, gcd(suf[i], pre[i+1]));

	// for(int i = 1; i <= n; ++i) cout << suf[i] << " \n"[i == n];
	
	// for(int i = 1; i <= n; ++i) cout << pre[i] << " \n"[i == n];
	cout << res;	
}