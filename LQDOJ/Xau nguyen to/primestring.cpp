#include <bits/stdc++.h>

using namespace std;

string yno[] = {"NO", "YES"};

bool check(int a) {
	if(a == 2) return true;
	if(a%2 == 0) return false;
	if(a < 2) return false;
	for(int i = 3; i*i <= a; i += 2) if(a%i == 0) return false;
	return true;
} 

void pr() {
	string s; cin >> s;
	map<char, int> m;
	for(auto x:s) ++m[x];
	int cnt = 0;
	for(char i = 'a'; i <= 'z'; ++i) if(m[i] == 1) ++cnt;
	cout << yno[check(cnt)] << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) pr();

	return 0;
}