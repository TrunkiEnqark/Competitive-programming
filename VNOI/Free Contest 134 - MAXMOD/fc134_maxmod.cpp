#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; 
	cin >> t;
	while(t--) {
		long long n; cin >> n;
		cout << (long long) (n - (n-1)/2) << '\n';
	}	
}