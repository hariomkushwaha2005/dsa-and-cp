#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

typedef long long ll;
typedef vector<long long> vll;

#define in(v) for (auto& _x : v) cin >> _x;

#define all(x) (x).begin(), (x).end()

string mikasa(string s, vector<pair<ll,char>> v){
    sort(v.rbegin(),v.rend());
    int x = s.size();
    vector<string> str(3);
    int a = 0;
    for(int i = 0; i < 3; i++){
        if(v[i].first < 1) break;
        if((x < 1 || s[x-1] != v[i].second) && (x < 3 || s[x-3] != v[i].second)){
            v[i].first--;
            str[i] = mikasa(s+v[i].second, v);
            if(str[i].size()>str[a].size()) a =i;
            v[i].first++;
        }
    }
    return str[a];
}

void solve() {
    ll r, g, b;
    cin>>r>>g>>b;
    vector<pair<ll,char>> v = {{r,'R'},{g,'G'},{b,'B'}};
    string s;
    cout<<mikasa(s,v)<<endl;
}

int main() {
    fast_io();

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}