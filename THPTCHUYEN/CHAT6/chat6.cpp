#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i=a; i<=b; ++i)

int main(){
 	int n;
 	cin>> n;
 	vector <int> a(n);
 	for (int &i:a) cin>> i;
 	sort(a.begin(), a.end());
 	int x, ans=0; cin>>x;
 	for (int i=0; i < a.size() -1; ++i){
 		int it= lower_bound(a.begin() + i + 1, a.end(), x - a[i]) - a.begin();
 		if (a[it] + a[i] == x) ++ans;
	 }
	cout<< ans;
	
}

