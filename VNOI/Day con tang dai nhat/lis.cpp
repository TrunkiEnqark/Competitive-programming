#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("lis.inp", "r", stdin);
	int n; cin >> n;
	multiset<int> S;
	while(n--) {
		int d; cin >> d;
		S.insert(d);
		multiset<int>::iterator it = S.lower_bound(d);
		++it;
		if(it != S.end()) S.erase(it);
	}
	cout << S.size() << '\n';
}

//Link: https://oj.vnoi.info/problem/lis