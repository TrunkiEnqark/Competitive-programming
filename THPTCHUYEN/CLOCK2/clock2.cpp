#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)

int main(){
	int a, b, c, d;
	cin>> a>> b>> c>> d;
	int ans= 0;
		if (b == 0){
			if (a == 0) ans=12; else 
			if (a>12) ans= a-12;
			else ans = a;
		}
	rep(i, a+1, c) {
		if (i >12) ans+= i - 11;
		else ans+=i+1;
	} ans--;
	if (b<=30) ++ans;
	if (d>=30) ++ans;
	cout<<ans;
}
//http://thptchuyen.ntucoder.net/Problem/Details/9934
