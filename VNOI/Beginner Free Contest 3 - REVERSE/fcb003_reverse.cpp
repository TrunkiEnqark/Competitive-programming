#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, a[100005];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> s >> m;
	n = s.size();
	for(int i = 1; i <= m; ++i) {
		int d; cin >> d;
		--d;
		reverse(s.begin()+d, s.begin()+(n - d - 1));
	}
	cout << s;
}