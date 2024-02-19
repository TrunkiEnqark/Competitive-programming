#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen(NAME".inp", "r", stdin);
	// freopen(NAME".out", "w", stdout);

	string s;
	cin >> s;
	reverse(all(s));
	int i = 0;
	while(i < (int) s.size() && s[i] == '1') ++i;
	if(i == (int) s.size()) {
		cout << 1;
		for(auto x:s) cout << 0;
	} else {
		s[i] = '1';
		for(int j = 0; j < i; ++j) s[j] = '0';
		reverse(all(s));
		cout << s;
	}

	return 0;
}