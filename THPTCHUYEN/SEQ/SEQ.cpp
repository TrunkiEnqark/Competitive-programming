#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n+1), maxL(n+1, 0), maxR(n+2, 0);
	
	for(int i = 1; i <= n; ++i) cin >> a[i];

    maxL[0] = maxR[n + 1] = INT_MIN;
	for(int i = 1; i <= n; ++i) maxL[i] = max(maxL[i-1], a[i]);
	for(int i = n; i >= 1; --i) maxR[i] = max(maxR[i+1], a[i]);

	ll res = LLONG_MIN;
	for(int i = 2; i < n; ++i) res = max(res, (ll) maxL[i - 1] - a[i] + maxR[i + 1]);
	cout << res;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9950