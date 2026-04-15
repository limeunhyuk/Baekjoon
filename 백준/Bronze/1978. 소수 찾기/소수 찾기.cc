#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1010;
bool prior[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    prior[1] = 1;
    for (int i = 2;i * i < MAX;i++) {
        if (!prior[i]) {
            int j = i;
            while (i * j < MAX) {
                prior[i * j++] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int t;
        cin >> t;
        if (!prior[t]) ans++;
    }

    cout << ans;
    return 0;
}