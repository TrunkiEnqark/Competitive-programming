#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	set<string> s; 
	while(t--) {
		int n; cin >> n;
		while(n--) {
			string str; cin >> str;
			s.insert(str);
		}
	}
	cout << s.size();
}