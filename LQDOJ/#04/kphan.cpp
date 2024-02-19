#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define maxn 1e6
#define pb push_back 
//#define st first
//#define nd second
#define fi cin
#define fo cout
//	ifstream fi("kphan.inp");
//	ofstream fo("kphan.out");
typedef vector <int> vi;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k, h, n;
	fi>>k>>h>>n;
//	vector <int> a(n+1);
	int a[5];
	rep(i, 1, n) 
		fi>>a[i];
	if (n==2){
		vi b(1, a[1]), c(1, a[2]);
		while (a[1]/2>0)	
			{b.pb(a[1]/2);a[1]/=2;}
		while (a[2]/2>0) 
			{c.pb(a[2]/2);a[2]/=2;}
		int i,  j; bool ok=true;
//		rep(i, 0, b.size()-1) fo<<b[i]<<' ';fo<<endl;
//		rep(i, 0, c.size()-1) fo<<c[i]<<' ';
		for (i=0; i<=b.size()-1 && ok; i++)
			for (j=0; j<=c.size()-1; j++)
				if (b[i]==c[j]) 
					{fo<<i+j;return 0;}
		fo<<i+j-1;
	} else if (n==3){
		vi b(1, a[1]), c(1, a[2]);
		
		while (a[1]/2>0)	
			{b.pb(a[1]/2);a[1]/=2;}
		while (a[2]/2>0) 
			{c.pb(a[2]/2);a[2]/=2;}
			
		int i,  j, ans, tmpi, tmpj; bool ok=true;
		for (i=0; i<=b.size()-1 && ok; i++)
			for (j=0; j<=c.size()-1; j++)
				if (b[i]==c[j]) 
					{tmpi=i, tmpj=j, ans=j+i, ok=false;break;}
					
		vi d(1, a[3]);
		while (a[3]/2>0) {
			d.pb(a[3]/2); a[3]/=2;}
		for(i=tmpi; i<=b.size()-1; i++)
			for(j=0; j<=d.size()-1; j++)
				if (b[i]==d[j]){
					ans+=(i-tmpi)+j;fo<<ans; return 0;
				}
	}
}
