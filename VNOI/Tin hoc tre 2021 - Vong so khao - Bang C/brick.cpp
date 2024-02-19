#include <bits/stdc++.h>

using namespace std;

const int L = (int) 1e7;

vector<int> prime;

void era() {
	vector<bool> p(L, true);
	// memset(p, true, sizeof(p));

	p[0] = p[1] = false;
	// for(int i = 0; i < 11; ++i) cout << p[i] << " \n"[i == 10];
	for(int i = 2; i*i <= L; ++i) 
		if(p[i]) for(int j = i*i; j <= L; j += i) p[j] = false;
	
	// for(int i = 0; i < 11; ++i) cout << p[i] << " \n"[i == 10];
	for(int i = 2; i <= L; ++i) if(p[i]) prime.push_back(i);
}

void pr() {
	int n; cin >> n;
	int k = 0;
	for(int p = prime[k], q = prime[k+1]; p*q <= n; p = prime[k++], q = prime[k]) {}
	cout << n - prime[k-1]*prime[k-2] << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	era();
	// for(int i = 0; i < 11; ++i) cout << prime[i] << ' ';
	int t; cin >> t;
	while(t--) {
		pr();
	}

	return 0;
}