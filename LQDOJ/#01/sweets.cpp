#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)
//#define fi cin
//#define fo cout
#define Int long long 
	ifstream fi("sweets.inp");
	ofstream fo("sweets.out");
vector <Int> a;
vector <Int> b;
vector <Int> d;

	int n, k;
	bool ok=true;
void tinh()
{
	vector <Int> c(n+1);
	rep(i, 1, n)c[b[i]]+=a[i];
	int tmp=c[1];
	rep(i, 2, k) if (c[i]!=tmp) return;
	rep(i, 1, n) fo<<b[i]<<' ';
	ok=false;
}

void thu(int i)
{
	if (ok)
	rep(j, 1, k) {
		b[i]=j, d[j]++;
		if (i==n ){
			int dem =k; rep(l, 1, k) if (d[l]>0) dem--;
			if (dem==0) tinh();
		}
		else thu(i+1);
	}
}
int main()
{
	fi>>n>>k;
	a.resize(n+1);
	b.resize(n+1);
	d.resize(n+1);
	rep(i, 1, n) fi>>a[i];
	thu(1);
	if (ok) fo<<-1;
}

