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

	int t; cin >> t;
	int res = 0;
	while(t--) {
		string s; cin >> s;
		s += "?";
		if((int) s.size() == 0) continue;
		char last = s[0];
		int cnt = 1;
		for(int i = 1; i < (int) s.size(); ++i) 
			if(s[i] == last) ++cnt; else {
				res = max(res, cnt);
				cnt = 1;
				last = s[i];
			}
	}
	cout << res;

	return 0;
}