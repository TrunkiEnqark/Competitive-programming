#include <bits/stdc++.h>

using namespace std;

const int N = 250000 + 5;

int trie[N][26], cnt = 0, f[N], c[N];

void calc(string s) {
	int u = 0;

	for(int i = 0; s[i]; ++i) {
		int ch = s[i] - 'a';
		if(trie[u][ch] == 0) 
			trie[u][ch] = ++cnt;
		u = trie[u][ch];
	}

	c[u] = 1;
}

void solve() {
	for(int i = cnt; i >= 0; --i) {
		for(int j = 0; j < 26; ++j) f[i] = max(f[i], f[trie[i][j]]);
		f[i] += c[i];
	}
	cout << f[0];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m; cin >> m;
	while(m--) {
		string s;
		cin >> s;
		calc(s);
	}
	solve();
}