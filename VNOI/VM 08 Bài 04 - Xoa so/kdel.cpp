#include <bits/stdc++.h>

using namespace std;

const int L = (int)7e5;

bool f[L];
vector<int> prime;

void era() {
	memset(f, true, sizeof(f));
	f[0] = f[1] = 0;
	for(int i = 2; i*i <= L; ++i) 
		if(f[i]) for(int j = i*i; j <= L; j += i) f[j] = false;
}

void init() {
	for(int i = 2; i <= L; ++i) if(f[i]) prime.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	init();
	string s = "";
	for(int i = 0; i < n; ++i) s += to_string(prime[i]);
	
}