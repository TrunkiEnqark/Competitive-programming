#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		priority_queue<int, vector<int>, greater<int> > qu;
		while(n--) {
			int d; cin >> d;
			qu.push(d);
		}
		ll res = 0;
		while(qu.size() > 1) {
			int a = qu.top(); qu.pop();
			int b = qu.top(); qu.pop();
			res += (a+b);
			qu.push(a+b);
		}
		cout << res << '\n';
	}
}