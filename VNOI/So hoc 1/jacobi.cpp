#include <bits/stdc++.h>

using namespace std;

const int m = 32767;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) {
		int a, n; cin >> a >> n;
		int k = a%n;
		bool ok = 1;
		for(int i = 1; i <= m; ++i) if(i*i == k) { cout << i << ' '; ok = 0; }
		cout << (ok ? "Khong co" : "") << '\n';
	}
}