#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

void process() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto &x:a) cin >> x;

	int cnt = 1, res = 0;
	for(int i = 1; i < n; ++i) 
		if(a[i] == a[i-1]) ++cnt;
			else {
				res = max(res, cnt);
				cnt = 1;
			}
	res = max(res, cnt);
	cout << (res + k > n ? n : res + k) << '\n'; 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) {
		process();
	}
}