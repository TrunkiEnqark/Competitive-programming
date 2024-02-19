#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
bool fre[25];
vector<int> x(25);
int res[100] = {0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144};

bool check(int a) {
	if(a < 2) return 0;
	for(int i = 2; i*i <= a; ++i) if(a%i == 0) return 0; 
	return 1;
}

void result() {
	if(!check(x[n] + 1)) return;
	for(int i = 1; i <= n; ++i) cout << x[i] << ' ';
	++cnt;
	cout << endl;
}

void trys(int i) {
	if(i > n) { result(); return; } else {
		for(int j = 1; j <= n; ++j) {
			if(!fre[j] && check(j + x[i-1])) {
				x[i] = j;
				fre[j] = 1;
				trys(i+1);
				if(cnt == 10000) return;
				fre[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cout << res[n] << '\n';
	n <<= 1;
	memset(fre, 0, sizeof(fre));
	x[1] = 1;
	fre[1] = 1;
	trys(2);
}