#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	fi>>n;
	vector <int> a(n);
	for (int &i:a) fi>>i;
	sort(a.begin(), a.end());
	fi>>q;
	rep(i, 1, q){
		int t; fi>>t;
		int it = upper_bound(a.begin(), a.end(), t) - a.begin();
		fo<<it<<endl;
	}
}

