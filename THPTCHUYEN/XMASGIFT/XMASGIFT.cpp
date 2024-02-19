#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)
#define N (int)1e6
long long a[N+1];
void init(){
	a[1]=1;
	rep(i, 2, N)  a[i] = a[i-1] +i;
	rep(i, 1, N) a[i]+=a[i-1];
}
int main(){
	init();
	int T, n;
	cin>> T;
	while (T--){
		cin>> n;
		cout<<a[n]<<endl;
		
	}
}
//http://thptchuyen.ntucoder.net/Problem/Details/10970
