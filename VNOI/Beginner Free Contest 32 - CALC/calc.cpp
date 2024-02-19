#include <bits/stdc++.h>

using namespace std;

const string yno[2] = {"no\n", "yes\n"};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t = 2;
	while(t--) {
		vector<long long> a(3);
		bool ok = 0;
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		do {
			if(a[0] + a[1] - a[2] == 0) { ok = 1; break; }
		} while(next_permutation(a.begin(), a.end()));
		cout << yno[ok];
	}
}