#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; i++)
#define pb push_back
#define Int long long 
#define fi cin
#define fo cout
//	ifstream fi("dance.inp");
//	ofstream fo("dance.out");
typedef vector <Int> vi;
typedef vector <vi> vii;

vii a;vii b;

bool find(vi a, int x)
{
	int be=0, en=a.size()-1;
	//fo<<j<<' ';rep(i, be, en) fo<<a[i]<<' '; fo<<endl;
	while (be<=en){
		int mid=(be+en)/2;
		if (a[mid]==x) return true;
		if (a[mid]>x) en=mid-1; else be=mid+1;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	fi>>n>>m;
	a.resize(n+1);
	m--;
	rep(i, 0, m) {
		Int x, y;
		fi>>x>>y;
		a[x].pb(y);
	}
	rep(i, 1, n) sort(a[i].begin(), a[i].end());
	Int ans=0;
	rep(i, 1, n) if (a[i].size()>0)
		rep(j, i+1, n)
			if (a[j].size()>0){
			int dem=0;
			rep(l, 0, a[i].size()-1){
				if (find(a[j], a[i][l])) dem++;
				if (dem==2){ ans++; break;}
			}
		}
	fo<<ans;
}

