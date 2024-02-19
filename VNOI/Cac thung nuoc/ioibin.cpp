#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 5; 

int s[N];

int find(int x) {
	return (s[x] == x ? x : s[x] = find(s[x])); 
}

void Disjoints_Sets(int u, int v) {
	s[find(u)] = find(v);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i = 1; i <= N; ++i) s[i] = i;

	int t; cin >> t;
	while(t--) {
		int u, v, c; cin >> u >> v >> c;
		--u, --v;
		if(c == 1) Disjoints_Sets(u, v); else cout << (find(u) == find(v)) << endl;
	}

	return 0;
}