#include <bits/stdc++.h>
#define fo(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;

//Sàng nguyên tố
vector<int> prime;
vector<bool> f((int)1e7, 1);
void era(int n) {
	f[0] = f[1] = 0;
	for(int i = 2; i*i <= n; ++i) if(f[i]) 
		for(int j = i*i; j <= n; j += i) f[j] = 0;
	fo(i,2,n) if(f[i]) prime.push_back(i);
}

int main() {
	int n; cin >> n;
	era((int)1e7);
    for (int p : prime)
    {
        if (f[p * 2 - 1])
        {
            if (--n == 0)
            {
                cout << p << ' ' << p << ' ' << p * 2 - 1;
                return 0;
            }
        }

        if (f[p * 2 + 1])
        {
            if (--n == 0)
            {
                cout << p << ' ' << p << ' ' << p * 2 + 1;
                return 0;
            }
        }
    }
}