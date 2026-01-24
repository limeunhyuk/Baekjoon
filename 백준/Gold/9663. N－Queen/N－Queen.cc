#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans;
bool y[16], z[32], w[32];

void queen_check(int x)
{
    if (x == N)
    {
        ans++;
        return;
    }
    for (int a = 0; a < N; a++)
    {
        if (!y[a] && !z[x - a + N - 1] && !w[x + a])
        {
            y[a] = 1;
            z[x - a + N - 1] = 1;
            w[x + a] = 1;
            queen_check(x + 1);
            y[a] = 0;
            z[x - a + N - 1] = 0;
            w[x + a] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ans = 0;
    queen_check(0);
    cout << ans;

    return 0;
}