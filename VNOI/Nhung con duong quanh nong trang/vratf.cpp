#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {
	if(n - k <= 1 || (n+k)%2) return 1;
	return solve((n+k)>>1, k) + solve((n-k)>>1, k);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	cout << solve(n, k);
}