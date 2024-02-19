#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define fi cin
#define fo cout
//	ifstream fi("pswap.inp");
//	ofstream fo("pswap.out");
vector <int> a;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	fi>>n;
	a.resize(n+1);
	rep(i, 1, n) fi>>a[i];
	int dem=0;
	rep(i, 1, n) if (a[i] != i) dem++;
	if (dem%2==0) fo<<(int) dem/2; else fo<<(int) dem/2+1;
}
