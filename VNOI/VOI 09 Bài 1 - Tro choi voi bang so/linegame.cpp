#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int t; cin >> t;
	long long s = t;
	while(n-- > 1) {
		int d; cin >> d;
		if(d > t) s += (d - t);
		t = d;
	}
	cout << s;
}