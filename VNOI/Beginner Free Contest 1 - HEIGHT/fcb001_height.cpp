#include <bits/stdc++.h>

#define ii 		pair<long long, int>
#define data 	first
#define index 	second

using namespace std;

void pr() {
	int n; cin >> n;
	vector<ii> a(n);
	vector<int> ans(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].data;
		a[i].index = i;
	}
	sort(a.begin(), a.end());
	int k = 0;
	ans[a[0].index] = k;
	for(int i = 1; i < n; ++i) {
		/*if(a[i].data == a[i-1].data) ans[a[i].index] = k; else */ans[a[i].index] = ++k;
	}  

	for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
	// cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	// freopen("museq.inp", "r", stdin);
	// freopen("museq.out", "w", stdout);
	// int t; cin >> t; while(t--) pr();
	// pr1();
	pr();
}