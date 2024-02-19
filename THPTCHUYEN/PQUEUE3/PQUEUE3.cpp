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

	priority_queue<int> q;
	int n; cin >> n;
	int res = 0;
	while(n--) {
		int c;
		cin >> c;
		if(c == 1) {
			int d, p;
			cin >> d >> p;
			q.push(p);
		} else {
			if(!q.empty()) {
				res += q.top();
				q.pop();
			}
		}
	}
	cout << res;

	return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/9727