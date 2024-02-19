#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(scanf("%*s%d", &n) != EOF) {
		double m = 5.0*n - 5;
		double a = 120.0 * m * m + 24.0;
		double b = (m + 1.0) * (m + 2.0) * (m + 3.0) * (m + 4.0);
		printf("%0.17lf\n", a/b);
	}
	return 0;
}