#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	map<char, char> m;
	m['A'] = 'T';
	m['T'] = 'A';
	m['G'] = 'C';
	m['C'] = 'G';
	string s; cin >> s;
	reverse(s.begin(), s.end());
	for(auto x:s) { cout << m[x];
		// if(x == 'A') cout << 'T';
		// if(x == 'T') cout << 'A';
		// if(x == 'G') cout << 'C';
		// if(x == 'C') cout << 'G';
	}
}