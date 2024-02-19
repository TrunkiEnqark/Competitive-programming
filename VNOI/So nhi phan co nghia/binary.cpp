#include <bits/stdc++.h>

#define fo(i,a,b)  for(int i = a; i <= b; ++i)
#define fod(i,a,b) for(int i = a; i >= b; --i)
#define N 50
#define ll long long

using namespace std;

ll c[N][N], dd[N];
int n, k;

ll get(int n, int k) { return ((n >> (k-1) & 1)); }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fo(i,0,34) c[0][i] = 1;
	fo(i,1,34) fo(j,i,34) c[i][j] = c[i-1][j-1] + c[i][j-1];
	while(cin >> n >> k) {
		ll t = 0, d = 0, res = 0;
		res += (k == 1);
		memset(dd, 0, sizeof(dd));
		fod(i,32,1) {
			if(!get(n,i)) { if(t) ++d; continue; }
			dd[i] = 1;
			t == 0 ? t = i : 0;
		}
		int dem = 0;
		fod(i,t-1,1) {
			if(dd[i] == 0) { ++dem; continue; }
			int tmp = k - dem - 1;
			if(tmp > i-1 || tmp < 0) continue;
			res += c[tmp][i-1];
		}
		res += (k == d);
		fod(i,t-1,k+1) {
			if(k > i-1) continue;
			res += c[k][i-1];
		}
		cout << res << '\n';
	}
}