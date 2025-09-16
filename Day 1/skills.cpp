#include <bits/stdc++.h>

using namespace std;

int n;
int x, k;
int s[1001];
int t[1001];
int taken[1001];

bool check(int level)
{
    int tTaken = 0;
    int iTaken = 0;
    for (int i = 0; i < level; i++)
    {
        if (taken[i])
        {
            tTaken += t[i];
            iTaken += 1;
        }
    }

    tTaken += t[level];
    iTaken++;

    if (tTaken <= x && iTaken <= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int rec(int level)
{
    if (level == n)
    {
        return 0;
    }

    // nTake
    int ans = rec(level + 1);
    // Take
    if (check(level))
    {
        taken[level] = 1;

        ans += max(ans, s[level] + rec(level + 1));

        taken[level] = 0;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> t[i];
    }
    cin >> x >> k;
    cout << rec(0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}