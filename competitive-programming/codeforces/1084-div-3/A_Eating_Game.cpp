#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Brute Force Approach TC - O(N*max(dishes)), SC - O(N)
void solveBrute()
{
    int n;
    cin >> n;

    vi dishes(n);
    for (auto &dish : dishes)
        cin >> dish;

    unordered_set<int> winners;
    for (int i = 0; i < n; ++i)
    {
        vi cur = dishes;
        int st = i;
        while (1)
        {
            int sum = 0;
            int last = -1;
            for (int j = 0; j < n; ++j)
            {
                int idx = (j + st) % n;
                if (cur[idx] > 0)
                {
                    cur[idx]--;
                    sum += cur[idx];
                    last = idx;
                }
            }
            if (sum == 0)
            {
                winners.insert(last);
                break;
            }
        }
    }

    int ans = winners.size();
    cout << ans << endl;
}

//Optimal Approach TC O(N), SC O(1);
void solveOptimal()
{
    int n;
    cin >> n;

    int maxDish = 0;
    int winners = 0;
    for (int i = 0; i < n; ++i)
    {
        int curDish;
        cin >> curDish;
        if (curDish > maxDish)
        {
            winners = 1;
            maxDish = curDish;
        }
        else if (maxDish == curDish)
            winners++;
    }

    cout << winners << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solveOptimal();
    }

    return 0;
}