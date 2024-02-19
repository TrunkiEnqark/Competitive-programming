#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define Int long
#define fi cin
#define fo cout
//	ifstream fi("bracket.inp");
//	ofstream fo("bracket.out");
Int n, ans=-INT_MAX;
vector <Int> a, b;
vector < vector <Int> > f;
//--------------------------------------------------------
void tinh(){
	Int s=0;
	rep(i, 1, n) s+=(a[i]*b[i]);
	//b[i]=-1-> tru
	//b[i]=1 -> cong
	//b[i]=0 -> ko lam gi het
	queue <int> c, d;
	rep(i, 1, n) {
		if (b[i]==1) c.push(i);
		if (b[i]==-1) d.push(i);
	}
	if (c.size()!=d.size()) return;
	while (!c.empty()){
		if (c.front()>d.front())return;
		c.pop(); d.pop();
	}
	ans=max(ans, s);
//	 if(ans==s){rep(i, 1, n) fo<<b[i]<<' '; fo<<endl;}
}

void back(int i){
	rep(j, -1, 1){
		b[i]=j;
		if (i==n) tinh(); else back(i+1);
	}
}

Int max(Int a, Int b, Int c){
	return max(a, max(b, c));
}
int main(){
	fi>>n;
	a.resize(n+1); b.resize(n+1);
	if (n<=10) {
		rep(i, 1, n)fi>>a[i];
		back(1);
		fo<<ans;
	} else {
		f.resize(n+1,vector <Int> (n+1, 0));
		rep(i, 1, n)
			rep(j, i, n-1)
				f[i][j] = max(f[i - 1][j], f[i-1][j-1] + a[i], f[i-1][j+1] - a[i]);
		fo<<f[n][0];
		priority_queue <Int, vector<Int>, greater<Int>> h;
		Int s=0;
		rep(i, 1, n){
			Int x;
			fi>>x;
			if (!h.empty() && h.top()<x) {
				s+=x-h.top(); h.pop();
				h.push(x); h.push(x);
			}else h.push(x);
		}
		fo<<s;
	}
}
