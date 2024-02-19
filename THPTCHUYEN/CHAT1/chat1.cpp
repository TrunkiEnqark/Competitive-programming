#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define fi cin
#define fo cout
#define Int long long 
vector <Int> a;
Int find(Int x, int n=a.size()){
	int l = 1, r = n;
	Int ans=0;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (a[mid] >= x) ans=a[mid], r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
int main(){
 	int n;
 	fi>>n;
 	a.resize(n+1, 0);
 	rep(i, 1, n) a[i]=(Int) i * i + 1;
 	fi>>n;
 	while (n--){
 		Int x;
 		fi>>x;
 		fo<< find(x) <<endl;
	 }
}
//http://thptchuyen.ntucoder.net/Problem/Details/4607
