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

const string yno[2] = {"NO\n", "YES\n"};

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
	while(n--) {
		int c; 
		cin >> c;
		if(c == 1) cout << q.size() << '\n';
		if(c == 2) cout << yno[q.empty()];
		if(c == 3) { int d; cin >> d; q.push(d); }
		if(c == 4) if(!q.empty()) q.pop();
		if(c == 5) { 
			if(q.empty()) cout << -1 << '\n'; else cout << q.top() << '\n';
		}
	}

	return 0;
}

//Nguồn: http://thptchuyen.ntucoder.net/Problem/Details/9725