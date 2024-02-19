#include <bits/stdc++.h>

#define pb push_back
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	// freopen("inp.txt", "r", stdin);
	char c;
	priority_queue<int> qu;
	while(cin >> c) {
		if(c == '+') {
			int d; cin >> d;
			if(qu.size() < 15000) qu.push(d);
		} else {
			if(!qu.empty()) {
				int t = qu.top(); 
				while(!qu.empty() && qu.top() == t) qu.pop();
			}
		}
	}
	vector<int> ans;
	int k = INT_MAX;
	ans.pb(k);
	for(; !qu.empty(); qu.pop()) {
		if(qu.top() != k) ans.pb(k = qu.top());
	}
	cout << ans.size() << '\n';
	fo(i, 0, ans.size() - 1) cout << ans[i] << '\n';
}