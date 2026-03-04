#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[10][10];
int map2[10][10];
int ans;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map2[i][j] = map[i][j];
			if (map2[i][j] == 2) q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			if (x2 >= 0 and x2 < N and y2 >= 0 and y2 < M) {
				if (map2[x2][y2] == 0) {
					map2[x2][y2] = 2;
					q.push({ x2, y2 });
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 0) cnt++;
		}
	}
	if (ans < cnt) ans = cnt;
}

void check(int index, int num) {
	while (index < N * M) {
		int x1 = index / M;
		int x2 = index % M;
		if (!map[x1][x2]) {
			map[x1][x2] = 1;
			if (num == 2) bfs();
			else check(index + 1, num + 1);
			map[x1][x2] = 0;
		}
		index++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ans = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	check(0, 0);

	cout << ans;

	return 0;
}