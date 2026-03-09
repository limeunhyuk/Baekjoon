#include <iostream>
using namespace std;

int n, m;
int tt[510][510];
int ans;

void dfs(int dir, int sum, int cnt, int x, int y) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}
	if (cnt == 1) {
		int temp = tt[x][y] + tt[x + 1][y] + tt[x - 1][y] + tt[x][y + 1] + tt[x][y - 1]
			- min(min(tt[x + 1][y], tt[x - 1][y]), min(tt[x][y + 1], tt[x][y - 1]));
		if (ans < temp) ans = temp;
	}
	if (dir != 1 && x + 1 <= n) dfs(3, sum + tt[x + 1][y], cnt + 1, x + 1, y);
	if (dir != 2 && y + 1 <= m) dfs(4, sum + tt[x][y + 1], cnt + 1, x, y + 1);
	if (dir != 3 && x > 1) dfs(1, sum + tt[x - 1][y], cnt + 1, x - 1, y);
	if (dir != 4 && y > 1) dfs(2, sum + tt[x][y - 1], cnt + 1, x, y - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> tt[i][j];
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			dfs(0, tt[i][j], 1, i, j);
		}
	}

	cout << ans;

	return 0;
}