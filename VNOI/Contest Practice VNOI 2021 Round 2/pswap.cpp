#include <bits/stdc++.h>

#define fo(i, a, b)  for(int i = a; i <= b; ++i)
#define fod(i, a, b) for(int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()

#define ll long long
#define pb push_back

using namespace std;

const int N = 5005;

int n, m;
vector<int> male[N], female[N];

void init() {
	cin >> n >> m;
	while(m--) {
		int u, v; cin >> u >> v;
		male[u].pb(v);
		female[v].pb(u);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	init();
	return 0;
}