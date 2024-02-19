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
const ll MOD = 1000000003;
const int N = 1000000;

ll hashT[N], POW[N];

ll getHashT(int i, int j) {
	return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a, b; cin >> a >> b;
	int n = a.size(), m = b.size();
	a = ' ' + a;
	b = ' ' + b;
	POW[0] = 1;
	fo(i,1,n) POW[i] = (POW[i-1] * base) % MOD;

	fo(i,1,n) hashT[i] = (hashT[i-1] * base + a[i] - 'a' + 1) % MOD;

	ll hashP = 0;
	fo(i,1,m) hashP = (hashP * base + b[i] - 'a' + 1) % MOD;

	fo(i,1,n-m+1) 
		if(hashP == getHashT(i, i + m - 1)) cout << i << ' ';

	return 0;
}