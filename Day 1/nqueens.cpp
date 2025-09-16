#include <bits/stdc++.h>
using namespace std;

int queens[20];

void printBoard(int n)
{
    cout << "+";
    for (int j = 0; j < n; j++)
        cout << "---+";
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < n; j++)
        {
            if (queens[i] == j)
                cout << " X |";
            else
                cout << " - |";
        }
        cout << "\n+";
        for (int j = 0; j < n; j++)
            cout << "---+";
        cout << "\n";
    }
    cout << "\n";
}

bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queens[i] == col)
        {
            cout << "Rejected: Queen at (" << row << "," << col
                 << ") conflicts vertically with (" << i << "," << queens[i] << ")\n";
            return false;
        }
        if (abs(i - row) == abs(queens[i] - col))
        {
            cout << "Rejected: Queen at (" << row << "," << col
                 << ") conflicts diagonally with (" << i << "," << queens[i] << ")\n";
            return false;
        }
    }
    cout << "Accepted: Placing Queen at (" << row << "," << col << ")\n";
    return true;
}

int rec(int level, int n)
{
    if (level == n)
    {
        cout << "\nSolution Found:\n";
        printBoard(n);
        return 1;
    }

    int ans = 0;
    for (int col = 0; col < n; col++)
    {
        cout << "\nConsidering position (" << level << "," << col << ")...\n";
        if (check(level, col))
        {
            queens[level] = col;
            printBoard(n);

            ans += rec(level + 1, n);

            cout << "Backtracking: Removing Queen from (" << level << "," << col << ")\n";
            queens[level] = -1;
            printBoard(n);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter n:" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
        queens[i] = -1;

    cout << "Starting N-Queens with n = " << n << "\n";
    int total = rec(0, n);
    cout << "\nTotal solutions: " << total << "\n";

    return 0;
}
