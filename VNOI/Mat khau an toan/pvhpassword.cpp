#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	int x; cin >> x;
	map<char, int> m;
	for(char i = 'a'; i <= 'z'; ++i) { 
		m[i] = x++;
		if(x > 25) x = 0;
	}
	int ans = 0;
	for(char &i:s) ans += m[i];
	cout << ans;
}