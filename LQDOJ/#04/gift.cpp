#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define maxn 1e6
#define pb push_back 
#define st first
#define nd second
#define fi cin
#define fo cout
//	ifstream fi("gift.inp");
//	ofstream fo("gift.out");
typedef vector <int> vi;
typedef vector <vi> vii;
typedef pair <int, int> ii;

int n, m, q, maxa=0;
vii a;
vector <vector <ii>> b(maxn);

void sub3(){
//	rep(i, 1, 20) sort(b[i].begin(), b[i].end());
//	rep(i, 0, b[2].size()-1) fo<<b[2][i].st<<' '<<b[2][i].nd<<endl;
//	fo<<b[2].size()-1;
	rep(k, 1, q){
		int u, v, x, y;
		fi>>u>>v>>x>>y;
		if (u==x && v==y) {fo<<1<<endl; continue;	}
		int dem=0;
		rep(i, 1, maxa){
			if (b[i].size()>0) rep(j, 0, b[i].size()-1) 
				if (b[i][j].st>=u && b[i][j].st<=x && b[i][j].nd>=v && b[i][j].nd<=y) {
					dem++; break;
				}
		}
		fo<<dem<<endl;
	}
}

int dem(int u, int v, int x, int y){
	set<int, greater<int> > res;
	rep(i, u, x)
		rep(j, v, y)
			res.insert(a[i][j]);
	return res.size();
}
void sub1(){
	rep(k, 1, q){
		int u, v, x, y;
		fi>>u>>v>>x>>y;
		if (u==x && v==y) {fo<<1<<endl; continue;	}
		fo<<dem(u, v, x, y)<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fi>>n>>m;
	a.resize(n+1, vi(m+1));
	rep(i, 1, n)
		rep(j, 1, m){
			fi>>a[i][j];
			maxa=max(maxa, a[i][j]);
			b[a[i][j]].pb(ii(i, j));
		}
	fi>>q;
	if (maxa<=20) sub3();
	//else if (n<=200 && m<=200 && q<=200) sub1();
	else sub1();
}
