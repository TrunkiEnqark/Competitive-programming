#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	ll d1 = 0, d2 = 0, d3 = 0;
	fo(t, 1, n) {
		int a, b, c; cin >> a >> b >> c;
		d1 += a;
		d2 += (b - t + 1);
		d3 += (c - t + 1);
	}
	cout << min({d1, d2, d3});

	return 0;
}