#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()

using namespace std;

stack<int> st;
priority_queue<int> qu;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) {
		int x; cin >> x;
		if(x == 1) {
			int d; cin >> d;
			st.push(d);
			qu.push(d);
		}
		if(x == 2) {
			// int d = st.top();
			if(st.top() == qu.top()) qu.pop();
			st.pop();
		}
		if(x == 3) {
			cout << qu.top() << "\n";
			// if(qu.size() > 1) qu.pop();
		}
	}	
}
