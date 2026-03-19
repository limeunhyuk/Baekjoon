#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cost[1010][3];
int dp[1010][3];
int ans = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int k = 0;k < 3;k++) {
		for (int i = 0;i < 3;i++) {
			if (i == k) dp[0][i] = cost[0][i];
			else dp[0][i] = 1e9;
		}
		for (int i = 1;i < n;i++) {
			for (int j = 0;j < 3;j++) {
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
			}
		}
		for (int j = 0;j < 3;j++) if (j != k && ans > dp[n - 1][j]) ans = dp[n - 1][j];
	}

	cout << ans;

	return 0;
}