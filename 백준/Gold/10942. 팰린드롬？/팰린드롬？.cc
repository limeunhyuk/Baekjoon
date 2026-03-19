#include <iostream>
using namespace std;

int n, m;
int list[2010];
bool dp[2010][2010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> list[i];
	}

	for (int i = 1;i <= n;i++) {
		dp[i][i] = 1;
		if (list[i - 1] == list[i]) dp[i - 1][i] = 1;
	}

	for (int k = 2;k < n;k++) {
		for (int i = 1;i + k <= n;i++) {
			int j = i + k;
			if (dp[i + 1][j - 1] && list[i] == list[j]) dp[i][j] = 1;
		}
	}

	cin >> m;
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << "\n";
	}

	return 0;
}