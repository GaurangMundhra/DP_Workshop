#include <bits/stdc++.h>

using namespace std;

int n;
int x, k;
int s[1001];
int t[1001];

int dp[101][101][101];

int rec(int level, int timeTaken, int skillsTaken)
{

    // pruning

    // base case
    if (level == n)
    {
        return 0;
    }

    // cache check

    if (dp[level][timeTaken][skillsTaken] != -1)
    {
        return dp[level][timeTaken][skillsTaken];
    }

    // compute / transition
    int ans = rec(level + 1, timeTaken, skillsTaken); // not take

    if (timeTaken + t[level] <= x && skillsTaken + 1 <= k)
    {
        ans = max(ans, s[level] + rec(level + 1, timeTaken + t[level], skillsTaken + 1)); // take
    }
    // return and save
    return dp[level][timeTaken][skillsTaken] = ans;
}

void solve()
{
    cin >> n >> x >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> t[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(0, 0, 0) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}