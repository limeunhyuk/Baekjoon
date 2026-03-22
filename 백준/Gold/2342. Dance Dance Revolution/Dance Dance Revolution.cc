#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int cost(int start, int end) {
	if (start == end) return 1;
	if (!start || !end) return 2;
	if (abs(start - end) % 2) return 3;
	return 4;
}

int Foot;
int dp[2][5];
bool flip;
const int MAX = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	fill(dp[0], dp[0] + 10, MAX);
	dp[0][0] = 0;

	while (n) {
		fill(dp[!flip], dp[!flip] + 5, MAX);

		for (int i = 0;i < 5;i++) {
			if (dp[flip][i] == MAX) continue;
			dp[!flip][i] = min(dp[!flip][i], dp[flip][i] + cost(Foot, n));
			dp[!flip][Foot] = min(dp[!flip][Foot], dp[flip][i] + cost(i, n));
		}

		Foot = n;
		flip = !flip;
		cin >> n;
	}

	int ans = MAX;
	for (int i = 0;i < 5;i++) {
		if (dp[flip][i] < ans) ans = dp[flip][i];
	}
	cout << ans;

	return 0;
}