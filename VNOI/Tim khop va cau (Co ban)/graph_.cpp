#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int N = 10005;

int n, m;
vector<int> a[N];
int CriticalEdge = 0;
bool CriticalNode[N];
int Num[N], Low[N], Time = 0;

void dfs(int u, int p) {
	int NumChild = 0;
	Low[u] = Num[u] = ++Time;
	for(int v : a[u]) {
		if(v != p) 
			if(Num[v] != 0) 
				Low[u] = min(Low[u], Num[v]);
			else {
				dfs(v, u);
				++NumChild;
				Low[u] = min(Low[u], Low[v]);

				if(Low[v] >= Num[v]) ++CriticalEdge;

				if(u == p) {
					if(NumChild >= 2) CriticalNode[u] = true;
				} else {
					if(Low[v] >= Num[u]) CriticalNode[u] = true;
				}
			}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while(m--) {
		int u, v; cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	for(int i = 1; i <= n; ++i) 
		if(!Num[i]) dfs(i, i);

	int count = 0;
	for(int i = 1; i <= n; ++i) count += (CriticalNode[i]);
	cout << count << ' ' << CriticalEdge;
}