#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;

const int N = 1e5;
const int oo = 0x3f3f3f3f;

int t[N<<2], n = 0;

void NLR(int i) {
	if(t[i] == 0 || t[i] == +oo || i > n) return;
	
	cout << t[i] << ' ';
	NLR(i*2);
	NLR(i*2+1);
}

void LNR(int i) {
	if(t[i] == 0 || t[i] == +oo) return;
	
	LNR(i*2);
	cout << t[i] << ' ';
	LNR(i*2+1);
}

void LRN(int i) {
	if(t[i] == 0 || t[i] == +oo) return;
	
	LRN(i*2);
	LRN(i*2+1);
	cout << t[i] << ' ';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("test.inp", "r", stdin);
	memset(t, +oo, sizeof(t));
	int i, l, r;
	while(cin >> i >> l >> r) {
		n += 2;
		// cout << i << ' ' << l << ' ' << r << '\n';
		t[i] = i;
		if(l != 0) t[i*2] 	  = l;
		if(r != 0) t[i*2 + 1] = r;
	}

	// for(int i = 1; i <= 12; ++i) cout << t[i] << ' ';
	LNR(1);
	cout << '\n';
	NLR(1);
	cout << '\n';
	LRN(1);
}