#include <bits/stdc++.h>

using namespace std;

const int N = 30005;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> a[N];
	for(int i = 1; i <= n; ++i) {
		int p, k; cin >> p >> k;
		a[k].push_back(p);
	}

	vector<int> f(N, 0);
	for(int i = 1; i <= N; ++i) {
		f[i] = f[i-1];
		for(auto x:a[i]) {
			f[i] = max(f[i], i - x + f[x]);
		}
	}
	cout << f[N];
}