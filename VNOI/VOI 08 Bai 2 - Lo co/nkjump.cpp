#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int a[n+1], f[n+1];
	for(int i = 0; i < n; ++i) cin >> a[i], f[i] = 1;
	sort(a, a+n);

	for(int k = 1; k < n; ++k) 
		for(int j = 0; j <= k; ++j) {
			int ai = a[k] - a[j];
			if(binary_search(a, a+j, ai) || binary_search(a+j+1, a+n, ai)) f[k] = max(f[k], f[j] + 1);
		}
	cout << *max_element(f, f+n);
}