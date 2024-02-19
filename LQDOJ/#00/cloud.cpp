#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<=b; i++)

	ifstream fi("cloud.in");
	ofstream fo("cloud.out");

typedef struct com{ //computer
	int c, f, p;//c core; f fast; p price
};
typedef vector <com> vi;

bool qt1(com a, com b) {return a.c>b.c;}
bool qt2(com a, com b) {return a.p>a.p;}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	fi>>n;
	vector <com> a(n+1);
	rep(i, 1, n){
		fi>>a[i].c>>a[i].f>>a[i].p;
	}
	int m;
	fi>>m;
	vector <com> b(n+1);
	rep(i, 1, m) {
	  fi>>b[i].c>>b[i].f>>b[i].p;		
	}
	
	sort (a.begin()+1, a.end(), qt1);
	sort (b.begin()+1, b.end(), qt2);
	
	int ans=0;
	rep(i, 1, m) {
		int mi=0, pos=0;
		rep(j, 1, n){
			if (a[j].c<b[i].c) break;
			if (a[j].c>=b[i].c && a[j].f>=b[i].f && b[i].p-a[j].p>mi)
				mi=b[i].p-a[j].p, pos=j;
		}
		if (pos>0) {a.erase(a.begin() + pos); ans+=mi, n--;}
	}
	fo<<ans<<endl;
}
