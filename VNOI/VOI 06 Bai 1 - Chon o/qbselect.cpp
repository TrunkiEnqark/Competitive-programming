#include <bits/stdc++.h>

#define fo(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = (int) 1e4 + 5;

int n, a[5][N], F[N][16], bit[16][5], sum[N][16];
bool can[16], com[16][16];

bool get(int k, int x) {
	return (x >> (k-1))&1;
}

void Enter() {
	cin >> n;
	for(int i = 1; i <= 4; ++i) 
		for(int j = 1; j <= n; ++j) cin >> a[i][j];
}

void Init() {
	memset(can, true, sizeof(can));
	memset(com, true, sizeof(com));
	memset(F, 0, sizeof(F));
	memset(sum, 0, sizeof(sum));

	fo(i, 1, n) fo(j, 0, 15) F[i][j] = INT_MIN;

	fo(i, 0, 15) fo(j, 1, 4) bit[i][j] = get(j, i);

	fo(i, 1, n) fo(j, 0, 15) {
			fo(k, 1, 4) sum[i][j] += (bit[j][k] * a[i][k]);
		}

	// fo(i, 1, n) fo(j, 0, 15) cout << sum[i][j] << " \n"[j == 15];

	fo(x, 0, 15) fo(k, 1, 3) if(get(k, x) && get(k+1, x)) can[x] = false;
	
	fo(i, 0, 15) fo(j, 0, 15) {
			if(!can[i] && !can[j]) com[i][j] = false;
				else {
					fo(k, 1, 4) 
						if(get(k, i) && get(k, j)) com[i][j] = false;
				}
		}	
}

void Process() {
	fo(i, 1, n) fo(j, 0, 15) 
			if(can[j]) {
				fo(k, 0, 15) 
				    if(com[j][k]) F[i][j] = max(F[i][j], F[i-1][k] + sum[i][j]);
			}
	fo(i, 1, n) fo(j, 0, 15) cout << F[i][j] << " \n"[j == 15];
}

void PrintResult() {
	int ans = INT_MIN;
	for(int x = 0; x < 16; ++x) ans = max(ans, F[n][x]);
	// cout << ans;
	if(ans != 0) cout << ans;
		else {
			ans = a[1][1];
			for(int i = 1; i <= n; ++i) 
				for(int j = 1; j < 5; ++j) ans = max(ans, a[i][j]);
			cout << ans;
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	Enter();
	
	Init();

	Process();

	PrintResult();

	return 0;
}