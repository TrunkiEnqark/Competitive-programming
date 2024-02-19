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

const int INF = (int)1e9;
const int base = 31;
const int MOD = 2111992;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k; cin >> n >> k;
	int f[n+1];
	f[0] = 1;
	fo(i,1,n) f[i] = ( (i > k) ? (f[i - 1] + f[i - k - 1]) : (f[i - 1] + 1) ) % MOD;
	cout << f[n];

	return 0;
}