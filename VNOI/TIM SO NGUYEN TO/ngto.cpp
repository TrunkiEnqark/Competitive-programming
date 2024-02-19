#include <bits/stdc++.h>
#define N 200000
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

vector<bool> f(N, 1);

void era() {
    f[0] = f[1] = 0;
    for(int i = 2; i*i <= N; ++i) if(f[i])
        for(int j = i*i; j <= N; j += i) f[j] = 0;
}

int main() {
    int a, b; cin >> a >> b;
    era();
    fo(i,a,b) if(f[i]) cout << i << endl;
}