#include <bits/stdc++.h>

#define NAME 		""
#define ll 			long long
#define ii 			pair<int, int>
#define ib 			pair<int, bool>
#define pll 		pair<ll, ll>
#define iii 		pair<int, ii>
#define iiii 		pair<ii, ii>
#define pb 			push_back;
#define fi 			first
#define se 			second
#define fo(i,a,b)	for(int i = a; i <= b; ++i)
#define fod(i,a,b)  for(int i = a; i >= b; --i)
#define rep(i,a)	for(int i = 0; i < a; ++i)
#define all(a)		a.begin(), a.end()
#define maxx(a,b,c) max(a, max(b, c))
#define minn(a,b,c) min(a, min(b, c)) 

using namespace std;

const int INF = 0x3f3f3f3f;
const int base = 31;
const ll MOD = 1000000003;

int n, k;
string a[111];
int cost[111][111];

string u, v;
int f[111][111];

int calc(int i = 0, int j = 0) {
	if(i >= int(u.size())) return int(v.size() - j);
	if(j >= int(v.size())) return int(u.size() - i);

	int &res = f[i][j];
	if(res != -1) return res;
	res = +INF;

	res = min(calc(i+1, j), calc(i, j+1)) + 1;
	if(u[i] == v[j]) res = min(res, calc(i+1, j+1)) + 1; 

	return res;
}

int g[1 << 22];

int solve(int i = 1, int mask = 0) {
	if(i > n) return 0;
	if(mask >> i & i) return solve(i+1, mask);

	int &res = g[mask];
	if(res != -1) return res;
	res = +INF;

	fo(j, i+1, n) {
		if(mask >> j & 1) continue;
		res = min(res, max(solve(i+1, mask | (1 << j)), cost[i][j]));
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	k = 1*n;
	n = 2*n;
	fo(i, 1, n) cin >> a[i];


	fo(i, 1, n) 
		fo(j, i+1, n) {
			u = a[i];
			v = a[j];
			memset(f, -1, sizeof(f));
			cost[i][j] = cost[j][i] = calc();
		}

	memset(g, -1, sizeof(g));
	cout << solve();

	return 0;
}