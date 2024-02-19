#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

vector<int> p(N);

void init() {
	for(int i = 1; i <= N; ++i) p[i] = i;

	for(int i = 2; i*i <= N; ++i) 
		for(int j = i*i; j <= N; j += i*i) p[j] = j / (i*i);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	int n, m; cin >> n >> m;
	int res = 0, i = 1, j = 1;
	while(i <= n && j <= n && i < j && i*j <= m) {
		if(p[i] == p[j]) ++res;
			else {
				for(int k = 1; k < j; ++k) if(p[k] == p[j]) ++res;
				++j;
			}
		++i, ++j;
	}
	cout << res;
}