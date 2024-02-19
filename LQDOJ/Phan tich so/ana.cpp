#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> L(n+1);
	L.assign(n+1, 0);
	L[0] = 1;
	fo(m,1,n) fo(v,m,n) L[v] += L[v-m];
	cout << L[n];
}