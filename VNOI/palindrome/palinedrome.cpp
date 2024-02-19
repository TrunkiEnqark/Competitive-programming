#include <bits/stdc++.h>
#define fo(i,a,b)  for(int i = a; i <= b; ++i)
#define fod(i,a,b) for(int i = a; i >= b; --i)
#define N 2005   

using namespace std;

int L[N][N];
string s, ans = "";

void op() {
	int n = s.size();
	fo(i,0,n) L[i][n+1] = L[0][i] = 0;
	fo(i,1,n) fod(j,n,1) if(s[i-1] == s[j-1]) L[i][j] = L[i-1][j+1] + 1; else L[i][j] = max(L[i-1][j], L[i][j+1]);

	int i = n, j = 1;
	while(i > 0 && j < n + 1) 
		if(s[i-1] == s[j-1]) {
			ans += s[i-1];
			--i, ++j;
		} else 
			if(L[i][j] == L[i-1][j]) {
				--i;
			} else ++j;
	cout << ans;
}

int main() {
	getline(cin, s);
	op();
}