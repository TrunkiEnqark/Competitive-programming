#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

struct Matrix {
	ll a[2][2] = {{0, 0}, {0, 0}};
	
	Matrix operator * (Matrix &o) {
		Matrix res;
		for(int i : {0, 1})
			for(int j : {0, 1}) 
				for(int k : {0, 1}) res.a[i][k] = (res.a[i][k] + (ll) a[i][j]*o.a[j][k])%MOD;
		return res;
	}
};

Matrix POW(Matrix a, ll n) {
	Matrix ans;
	ans.a[0][0] = ans.a[1][1] = 1;
	while(n > 0) {
		if(n&1) ans = ans * a;
		a = a*a;
		n >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n; cin >> n;
	Matrix res;
	res.a[0][0] = 19;
	res.a[0][1] = 7;
	res.a[1][0] = 6;
	res.a[1][1] = 20;
	cout << POW(res, n).a[0][0];
}