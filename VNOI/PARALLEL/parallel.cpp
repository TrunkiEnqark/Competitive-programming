#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

const int oo = (int)1e9;
const string yno[2] = {"NO\n", "YES\n"};

bool pr() {
	vector<int> a(12);
	fo(i,0,11) cin >> a[i];
	if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 && a[6] == 0 && a[7] == 0 && a[8] == 0 && a[9] == 0 && a[10] == 0 && a[11] == 0) return 0;
	sort(a.begin(), a.end());
	cout << yno[a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && 
				a[4] == a[5] && a[5] == a[6] && a[6] == a[7] &&
				a[8] == a[9] && a[9] == a[10] && a[10] == a[11]];

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("parallel.inp", "r", stdin);
	while(pr()) {}
}