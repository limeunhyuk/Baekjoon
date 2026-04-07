#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool board[11][11];
bool neg[20];
int ans[2];

void dfs(int pos, int num, bool odd) {
    if (num + (2 * n - pos) / 2 <= ans[odd]) return;

    if (pos > 2 * n - 2) {
        if (ans[odd] < num) ans[odd] = num;
        return;
    }
    for (int i = max(0, pos - n + 1);i <= min(pos, n - 1);i++) {
        int j = pos - i;
        if (board[i][j] && !neg[i - j + n]) {
            neg[i - j + n] = 1;
            dfs(pos + 2, num + 1, odd);
            neg[i - j + n] = 0;
        }
    }
    dfs(pos + 2, num, odd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);
    dfs(1, 0, 1);
    cout << ans[0] + ans[1];

    return 0;
}