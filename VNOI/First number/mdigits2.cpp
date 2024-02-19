#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s = "";
	int n; cin >> n;
	for(int i = 0; i <= 100000; ++i) s += to_string(i);
	cout << s.find(to_string(n), 0);
}