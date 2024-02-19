#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n; 
	ll f[11];
	memset(f, 0, sizeof(f));
	f[0] = f[1] = 1;
	for(int i = 2; i <= 10; ++i) {
		ll c = 1;
		for(int j = 1; j <= i; ++j) { 
			c = c * (i-j+1) / j;
			f[i] += c * f[i-j];
		}
	}
	while(scanf("%d", &n) && n != -1) {
		printf("%llu\n", f[n]); 
	}
	return 0;
}