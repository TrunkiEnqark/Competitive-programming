#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define Int long long 
#define fi cin
#define fo cout
//	ifstream fi("convol.inp");
//	ofstream fo("convol.out");
typedef vector <Int> vi;
typedef vector <vi> vii;
vi a;
vi b;

Int tinh(int x, int y, int k){
	Int tmp=0;
	for (int i=x, j=y; i<=x+k; i++, j++)
		tmp+=a[i]*b[j];
	return tmp;
}
int main()
{
	int n;
	fi>>n;
	a.resize(n+1);
	b.resize(n+1);
	rep(i, 1, n) fi>>a[i];
	rep(i, 1, n) fi>>b[i];
	Int ans=LLONG_MIN;
	//--------------n<=50-----------------------------------
//	rep(k, 1, n){
//		rep(i, 1, n-k)
//			rep(j, 1, n-k)
//				ans=max(ans, tinh(i, j, k));
//	}
	//---------------------------------------------------
	vii f(n+1, vi(n+1));
//	rep(i, 1, n) f[1][i]=a[1]*b[i];
//	rep(i, 1, n) f[i][1]=a[i]*b[1];
	rep(i, 1, n)
		rep(j, 1, n) 
		  f[i][j] = max(f[i-1][j-1] + a[i]*b[j], a[i]*b[j]), ans = max(ans, f[i][j]);
	cout << ans;
}
