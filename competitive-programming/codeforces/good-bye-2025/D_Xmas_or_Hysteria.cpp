#pragma GCC optimize("O3,unroll-loops")

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
    int n, m;
    cin >> n >> m;

    vi v(n);
    for (auto &x : v)
        cin >> x;

    if (m > n / 2)
    {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> ops;
    int l = 0, r = n - 1;
    while ((r - l + 1) / 2 > m)
    {
        int x = min(v[l], v[r]) == v[l] ? l : r;
        int y = x == r ? l : r;
        ops.push_back({x, y});
        int sub = v[r];
        v[r] -= v[l];
        v[l] -= sub;

        if (v[l] <= 0)
            l++;
        if (v[r] <= 0)
            r--;
    }

    int lastalive = l;
    while (l < r)
    {
        int x = max(v[l], v[r]) == v[l] ? l : r;
        int y = x == r ? l : r;
        ops.push_back({x, y});
        int sub = v[r];
        v[r] -= v[l];
        v[l] -= sub;
        l++;
        r--;
        lastalive = x;
    }
    if (l == r)
    {
        ops.push_back({l, lastalive});
    }

    cout << ops.size() << endl;
    for (auto &it : ops)
    {
        cout << it.first + 1 << " " << it.second + 1 << endl;
        }
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