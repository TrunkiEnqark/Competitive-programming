#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout
#define Int long long 
vector <Int> a;
char ok[2]={'N', 'Y'};
Int find(Int x){
	int l = 0, r = a.size() - 1;
	Int ans;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (a[mid] <= x) ans = a[mid], l = mid + 1; 
		else r = mid - 1;
	} return ans;
}
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
// 		vector <Int>::iterator it = upper_bound(a.begin(), a.end(), x);
// 		--it;
// 		fo<< *it<< endl;
		fo<< find(x)<<endl;
	 }
}
//http://thptchuyen.ntucoder.net/Problem/Details/4609
