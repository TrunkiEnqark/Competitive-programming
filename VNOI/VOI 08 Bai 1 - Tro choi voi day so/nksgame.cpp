#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m; cin >> m;
	int n = m, l = 9*to_string(m).size();
	
	for(int i = l; i >= 0; --i) {
		int tmp = n-i, j = 0;
		while(tmp > 0) {
			j += tmp%10;
			tmp /= 10;
		}
		if(i == j) { cout << n-i; return 0; }
	}
	cout << 0;
}