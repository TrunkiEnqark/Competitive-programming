#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout
#define Int long long
//		ifstream fi("input.inp");
//		ofstream fo("output.out");
bool ok(Int n){
	if (n<2) return 0;
	rep(i, 2, sqrt(n)) 
		if(n % i == 0) return 0;
	return true;
}
int main(){
	Int n;
	fi>>n;
	if (ok(n)) cout<<"YES"; else cout<<"NO";
}

