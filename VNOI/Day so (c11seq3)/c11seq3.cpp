#include <bits/stdc++.h>

using namespace std;

const int f1[] = {1, 2, 4, 8, 16, 23, 46, 29, 58, 116, 223, 446, 289, 578, 1156, 1223, 2446, 2489, 4789, 5789, 11578, 12356, 12247, 24449};
const int f2[] = {244445, 48889, 77789, 155578, 111356, 122227};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	if(n <= 24) cout << f1[n-1]; else cout << f2[n%6];
}