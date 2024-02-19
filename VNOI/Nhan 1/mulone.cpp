#include <bits/stdc++.h>

using namespace std;

void pr() {
	int n; cin >> n;
	char res[2000005];
	int m = 0, p = n+n-2;
	for(int i = 1; i <= n; ++i, --p) {
		m += i;
		res[p] = m%10 + '0';
		m /= 10; 
	}

	for(int i = n-1; i > 0; --i, --p) {
		m += i;
		res[p] = m%10 + '0';
		m /= 10;
	}

	if(m) cout << m;
	res[n+n-1] = 0; cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	// freopen("out.txt", "w", stdout);
	int t; cin >> t;
	while(t--) pr();
}