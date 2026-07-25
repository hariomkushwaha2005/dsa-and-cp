#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    vector<long long> arr(n, 0);
    long long maxx = 0;
    long long ans = 0;
    long long mi = 0, mval = 0, smval = 0;
    long long maxwait = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mval <= v[i])
        {
            smval = mval;
            mval = v[i];
            mi = i;
        }
        else if (smval < v[i])
            smval = v[i];

        long long curwait = mval - v[i];
        ans += curwait;
        arr[mi] += min(mval - smval, curwait);
        maxx = max(maxx, arr[mi]);
        maxwait = max(maxwait, curwait);
    }

    cout << ans - max(maxwait, maxx) << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}