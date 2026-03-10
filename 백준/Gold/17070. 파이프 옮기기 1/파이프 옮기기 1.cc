#include <iostream>
#include <queue>
using namespace std;

int n;
queue<pair<int, pair<int, int>>> q;
int m[20][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> m[i][j];
		}
	}

	int ans = 0;
	q.push({ 1,{0,1} });

	while (!q.empty()) {
		int ax = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			ans++;
			continue;
		}

		if ((ax == 2 || ax == 3) && x + 1 < n && !m[x + 1][y]) q.push({ 2, {x + 1,y} });
		if ((ax == 1 || ax == 3) && y + 1 < n && !m[x][y + 1]) q.push({ 1, {x,y + 1 } });
		if (y + 1 < n && x + 1 < n && !m[x + 1][y + 1] && !m[x + 1][y] && !m[x][y + 1]) q.push({ 3, {x + 1,y + 1} });
	}
	
	cout << ans;

	return 0;
}