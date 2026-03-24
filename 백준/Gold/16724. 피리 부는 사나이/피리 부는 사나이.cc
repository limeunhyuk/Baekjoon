#include <iostream>
using namespace std;

int n, m;
int dir[1010][1010];
int visited[1010][1010];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			char c;
			cin >> c;
			if (c == 'D') dir[i][j] = 0;
			if (c == 'U') dir[i][j] = 1;
			if (c == 'R') dir[i][j] = 2;
			if (c == 'L') dir[i][j] = 3;
		}
	}

	int idx = 1;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (visited[i][j]) continue;
			int x = i, y = j;
			while (!visited[x][y]) {
				visited[x][y] = idx;
				int temp = dir[x][y];
				x += dx[temp];
				y += dy[temp];
			}
			if (visited[x][y] == idx) ans++;
			idx++;
		}
	}

	cout << ans;

	return 0;
}