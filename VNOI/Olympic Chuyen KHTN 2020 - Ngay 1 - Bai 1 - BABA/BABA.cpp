#include <bits/stdc++.h>

#define fo(i,a,b) for(int i = a; i <= b; ++i)
#define ll long long

using namespace std;

const int L = 30303;

void pr1(string s) {
	ll cnt = 0;
	for(int i = 1; i <= L; ++i) {
		int d = 33*i;
		string F = to_string(d), tmp = s;
		for(int pos = tmp.find(F, 0); pos != -1; tmp[pos] = '?', ++cnt) {} 
	}
	cout << cnt;
}

void pr2(string s) {
	for(int i = L; i > 0; --i) {
		int d = 33*i;
		if(s.find(to_string(d), 0) != -1) {
			cout << d;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int type; cin >> type;
	if(type == 1) pr1(s); else pr2(s);
}