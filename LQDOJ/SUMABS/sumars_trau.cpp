#include <bits/stdc++.h>
using namespace std;
const int cs = 1e5 + 7;
const long long mod = 1e9 + 7;
const int INF = mod;
const int maxN = 1e3 + 7;

#define input cin
#define output cout
#define ll long long 
#define pii pair<int,int>

int n,k;
int d[100];
ll sum = 0;
ll cnt = 0;

void init() {
    memset(d,true,sizeof(d));
    sum = 0;
}

void BackTrack(int i) {
    if (sum > k) {
        return;
    }
    for (int j = 1;j<=n;j++) {
        if (d[j]) {
            sum += abs(i - j);
            d[j] = false;
            if (i == n) {
                if (sum == k) {
                    cnt++;
                }
            } else {
                BackTrack(i + 1);
            }
            sum -= abs(i - j);
            d[j] = true;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    input.tie(NULL);
    output.tie(NULL);
    input >> n >> k;
    init();
    BackTrack(1);
    output << cnt;
    return 0;
}