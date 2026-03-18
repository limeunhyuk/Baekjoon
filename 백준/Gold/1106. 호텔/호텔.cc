#include <iostream>
using namespace std;

int c, n;
int dp[1210];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> c >> n;
	c += 110;

	for (int i = 1;i < c;i++) {
		dp[i] = 1e9;
	}

	for (int i = 0;i < n;i++) {
		int cost, people;
		cin >> cost >> people;
		for (int j = 0;j < c;j++) {
			if (dp[j + people] > dp[j] + cost) dp[j + people] = dp[j] + cost;
		}
	}

	int ans = 1e9;
	for (int i = c - 110;i < c;i++) {
		if (ans > dp[i]) ans = dp[i];
	}

	cout << ans;

	return 0;
}