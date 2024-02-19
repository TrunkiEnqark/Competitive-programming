#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int pos = 0, nega = 0;
	while(n--) {
		char s[31]; cin >> s;
		if(s[0] == '-') ++nega; else ++pos;
	}
	cout << nega << ' ' << pos;
}