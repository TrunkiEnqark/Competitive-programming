#include <bits/stdc++.h>

using namespace std;

map<string, string> ma;

void drill(string qu, string ans) {
	ma[qu] = ans;
}

string query(string qu) {
	return ma[qu];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	
	while(n--) {
		string a, b; cin >> a >> b;
		drill(a, b);
	}
	while(m--) {
		string s; cin >> s;
		cout << query(s) << endl;
	}
}