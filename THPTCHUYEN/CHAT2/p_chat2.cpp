#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout
#define Int long long 
vector <Int> a;
char ok[2]={'N', 'Y'};
int main(){
 	int n;
 	fi>>n;
 	a.resize(n);
 	for (auto &i:a) fi>>i;
 	sort(a.begin(), a.end());
 	fi>>n;
 	while (n--){
 		Int x;
 		fi>>x;
 		fo<< ok[upper_bound(a.begin(), a.end(), x) != lower_bound(a.begin(), a.end(), x)] <<endl;
	 }
}
//http://thptchuyen.ntucoder.net/Problem/Details/4607
