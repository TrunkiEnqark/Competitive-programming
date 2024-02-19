#include <bits/stdc++.h>

using namespace std;

int n, l, w[6005], f[6005];

int main() {
	scanf("%d%d", &n, &l);
	for(int i = 1; i <= n; ++i) { scanf("%d", w+i); w[i] += w[i-1]; }
	
	for(int i = 1; i <= n; ++i) {
		f[i] = INT_MAX;
		for(int j = i-1; j >= 0; --j) {
			if(w[i] - w[j] > l) continue;
			f[i] = min(f[i], max(f[j], l-(w[i] - w[j])));
		}
	}

	printf("%d", f[n]);
}