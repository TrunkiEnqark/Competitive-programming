#include <bits/stdc++.h>

#define ll long long

using namespace std;

int calc(int a, int b, int ma, int mb) {
	if(a < b) swap(a, b), swap(ma, mb);
	if(ma == 0) return min(b, mb);
	if(mb == 0) return min(a, ma);
	if(a > (ll) b * ma) return min(a, ma*(b+1)) + b;
	return a + b;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int a, b, ma, mb; cin >> a >> b >> ma >> mb;
		cout << calc(a, b, ma, mb);
	}
}