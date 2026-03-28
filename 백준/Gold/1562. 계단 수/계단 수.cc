#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1024;
const int MAX2 = 1e9;
int n;
long long dp[2][10][MAX];
// 메모리 절약을 위해 cur을 idx로 2개의 배열을 번갈아가며 사용한다.
bool cur = 1;

// 기존 visited에 새로 들어온 x를 추가해서 반환한다.
int addbit(int len, int x) {
	return len | (1 << x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int j = 1;j < 10;j++) dp[cur][j][1 << j] = 1;

	for (int i = 2;i <= n;i++) {
		for (int j = 0;j < 10;j++) {
			for (int k = 0;k < MAX;k++) {
				if (!dp[cur][j][k]) continue;
				if (j - 1 >= 0) {
					dp[!cur][j - 1][k | (1 << (j - 1))] += dp[cur][j][k] % MAX2;
				}
				if (j + 1 < 10) {
					dp[!cur][j + 1][k | (1 << (j + 1))] += dp[cur][j][k] % MAX2;
				}
			}
		}
		memset(dp[cur], 0, sizeof(dp[cur]));
		cur = !cur;
	}

	long long ans = 0;
	for (int i = 0;i < 10;i++) {
		ans += dp[cur][i][MAX - 1] % MAX2;
	}
	cout << ans % MAX2;

	return 0;
}