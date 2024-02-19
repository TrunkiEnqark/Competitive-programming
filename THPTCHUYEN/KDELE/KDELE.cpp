#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

const int N = 1e7 + 7;

int n, k;
bool flag[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> k; 
    int cnt = 0;
    memset(flag, true, sizeof(flag));
    for(ll i = 2; i <= n; ++i) if(flag[i]) {
        ++cnt;
        flag[i] = false;
        if(cnt == k) {
            cout << i;
            return 0;
        }
        for(ll j = i*i; j <= n; j += i) if(flag[j]) {
            ++cnt;
            flag[j] = false;
            if(cnt == k) {
                cout << j;
                return 0;
            }
        } 
    }
    
    cout << -1;
    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/8526