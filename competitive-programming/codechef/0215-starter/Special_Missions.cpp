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
    // Your logic goes here
    int n, c;

    cin >> n >> c;

    vi v(n);
    for (auto &x : v)
    {
        cin >> x;
    }

    string s;
    cin >> s;

    ll normal = 0, special = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            normal += v[i];
        else
            special += v[i];
    }
    if (special > c && normal >= c)
        cout << normal + special - c << endl;
    else cout << normal << endl;
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