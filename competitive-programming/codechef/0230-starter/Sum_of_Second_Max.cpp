#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size() 

inline void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    // Your logic goes here
    int n;
    cin >> n;

    vi v(n);
    for(auto &x : v) cin >>x;
    
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int maxx = v[i], smax = v[i + 1];
        for(int j = i + 1; j < n; j++){
            if(v[j]>maxx) {
                smax = maxx;
                maxx = v[j];
            }
            else smax = max(smax, v[j]);
            ans += smax;
        }
    }
    cout << ans << endl;
}

int main() {
    fast_io();
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}