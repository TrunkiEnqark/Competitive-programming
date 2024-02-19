#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans=0, i=0;
	vector <int> a;
	while (cin>> n){
		ans+=n;i++;
	}
	cout<< ans - i + 1;
}
//http://thptchuyen.ntucoder.net/Problem/Details/10959
