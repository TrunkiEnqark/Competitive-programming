#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b; 
	cin >> a >> b;
	int next[N+1];
	next[0] = -1;
	for(int i = 1; b[i]; ++i) {
		int j = next[i-1];
		while(j >= 0 && b[j+1] != b[i]) j = next[j];
		if(b[j+1] == b[i]) ++j;
		next[i] = j;
	}

	for(int i = 0, j = -1; a[i]; ++i) {
		while(j >= 0 && a[i] != b[j+1]) j = next[j];
		if(a[i] == b[j+1]) ++j;
		if(b[j+1] == 0) {
			cout << i - j + 1 << ' ';
			j = next[j];
		}
	}
}