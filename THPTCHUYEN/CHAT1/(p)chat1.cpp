#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout
#define Int long long 
vector <Int> a;
int main(){
 	int n;
 	fi>>n;
 	a.resize(n+1, 0);
 	rep(i, 1, n) a[i]=(Int) i * i + 1;
 	fi>>n;
 	while (n--){
 		Int x;
 		fi>>x;
 		fo<< *lower_bound(a.begin(), a.end(), x) <<endl;
	 }
}
//http://thptchuyen.ntucoder.net/Problem/Details/4607
