#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    else return gcd(b, a);
}

int main() {
    int n;
    cin >> n;
    long long ms = 1;
    for(int i = 1; i <= n; ++i) ms *= i;
    long long ts = 0;
    for(int i = 1; i <= n; ++i) ts += ms/i;
    
    cout << ts << endl << ms << endl;

    long long g = gcd(ms, ts);
    // cout << ts/g << ' ' << ms/g;
}