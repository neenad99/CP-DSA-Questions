// To know about the thought process, checkout the editorial on this link : https://discuss.codechef.com/t/divpairs-editorial/94960

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

ll k, l, m, n, x, y, z;
ll ans = 0;

vector<ll> factors(int x)
{
    vector<ll> ans;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i)
            continue;

        ans.push_back(i);
        if (i * i != x)
            ans.push_back(x / i);
    }

    return ans;
}

void solve(int tc = 0)
{
    cin >> n;
    vector<pair<int, int>> arr(n);

    for(ll i = 1; i<=n; i++)
    {
        cin >> x;
        int g = __gcd(i, x);
        arr.push_back({i / g, x / g});
    }

    unordered_map<int, unordered_map<int, int>> dp;
    ans = 0;

    for (auto it : arr)
    {
        auto facs = factors(it.second);

        for (auto b1 : facs)
            ans += dp[it.first][b1];

        for (auto b1 : facs)
            dp[b1][it.first]++;
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}

