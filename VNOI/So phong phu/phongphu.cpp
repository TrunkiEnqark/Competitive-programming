#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define N (int)1e5

using namespace std;

bool check(int a) {
	int s = 1;
	fo(i,2,a/2) if(a%i == 0) s += i;
	return s > a;
}

int s[N+5];

void Init() {
	fo(i,1,N) for(int j = 2*i; j <= N; j += i) s[j] += i;
}

int main() {
	Init();
	int a, b; cin >> a >> b;
	int ans = 0;
	fo(i,a,b) ans += (s[i] > i);
	cout << ans;
}