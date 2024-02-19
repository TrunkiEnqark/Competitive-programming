#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	int res = 0;
	for(; a <= b; a *= 3, b *= 2, ++res) {}
	cout << res;
}