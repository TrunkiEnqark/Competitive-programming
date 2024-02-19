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

const int base = 31;
const int MOD = 2111992;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	vector<vector<int> > a(n+1, vector<int> (m+1, 0));
	fo(i, 1, n) fo(j, 1, m) {
		cin >> a[i][j];
		if(a[i][j] == 0) a[i][j] = -1;
	}

	
	return 0;
}