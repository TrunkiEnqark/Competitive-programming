#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1000000007;

struct matrix {
	int c[2][2] = {{0, 0}, {0, 0}};
};

matrix operator * (matrix a, matrix b) {
	matrix res;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j) {
			// res.c[i][j] = 0ll;
			for(int k = 0; k < 2; ++k) res.c[i][k] = (res.c[i][k] + (ll) a.c[i][j] * b.c[j][k])%MOD;
		}
	return res;
}

matrix poww(matrix a, ll n) {
	matrix res;
	res.c[0][0] = res.c[1][1] = 1;
	while(n > 0) {
		if(n&1) res = res*a;
		n >>= 1;
		a = a*a;
	}
	return res;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n; cin >> n;
	matrix ans;
	ans.c[0][0] = 0;
	ans.c[0][1] = ans.c[1][0] = ans.c[1][1] = 1;
	ans = poww(ans, n);
	cout << ans.c[1][0]%MOD;
}