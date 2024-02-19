#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 3005;

ll dp[N][N], a[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	// deque<long long> q;
	// for(int i = 0; i < n; ++i) {
	// 	long long d; 
	// 	cin >> d;
	// 	q.push_back(d);
	// }

	// long long a = 0, b = 0;
	// bool ok = true;
	// while(!q.empty()) {
	// 	if(ok) a += max(q.front(), q.back()); else b += max(q.front(), q.back());
	// 	ok = !ok;
	// 	if(q.front() >= q.back()) q.pop_front(); else q.pop_back();
	// }
	// cout << max(a-b, b-a);

	for(int i = 0; i < n; ++i) cin >> a[i], dp[i][i] = a[i];

	for(int i = n-1; i >= 0; --i)
		for(int j = i+1; j < n; ++j)
			dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
	cout << dp[0][n-1];
}