#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int size[6];
    for (int i = 0;i < 6;i++) cin >> size[i];
    int t, p;
    cin >> t >> p;

    int sum = 0, tans = 0;
    for (int i = 0;i < 6;i++) {
        sum += size[i];
        tans += (size[i] + t - 1) / t;
    }

    cout << tans << "\n" << sum / p << " " << sum % p;

    return 0;
}