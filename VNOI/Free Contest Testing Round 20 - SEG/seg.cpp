#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;
	int a[s.size()+1];
	int p = s.find(">", 0);
	int k = p;
	for(int i = 0; i < p; ++i) a[i] = k--;

	for(int i = p; i < (int) s.size(); ++i) {
		if(s[i] == '<') a[i] = a[i-1] + 1; else a[i] = a[i-1] - 1;
	}
	int ans = 0;
	for(int i = 0; i < (int) s.size(); ++i) ans += a[i];
	cout << ans;
}