#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visit[10010];
char map[11][11];
vector<int> cnt[11];
int rx, ry, bx, by;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int cal(int x1, int y1, int x2, int y2) {
	return x1 * 1000 + y1 * 100 + x2 * 10 + y2;
}

int red_push(int idx) {
	int cnt = 1;
	int new_x = rx + dx[idx];
	int new_y = ry + dy[idx];
	if (map[new_x][new_y] == '#') return 0;
	while (map[new_x][new_y] != '#') {
		rx = new_x;
		ry = new_y;
		new_x = rx + dx[idx];
		new_y = ry + dy[idx];
		cnt++;
		if (map[rx][ry] == 'O') return -1;
	}
	return cnt;
}

int blue_push(int idx) {
	int cnt = 1;
	int new_x = bx + dx[idx];
	int new_y = by + dy[idx];
	if (map[new_x][new_y] == '#') return 0;
	while (map[new_x][new_y] != '#') {
		bx = new_x;
		by = new_y;
		new_x = bx + dx[idx];
		new_y = by + dy[idx];
		cnt++;
		if (map[bx][by] == 'O') return -1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') rx = i, ry = j;
			if (map[i][j] == 'B') bx = i, by = j;
		}
	}
	int temp = cal(rx, ry, bx, by);
	cnt[0].push_back(temp);
	visit[temp] = 1;
	for (int i = 1;i <= 10;i++) {
		for (int j = 0;j < cnt[i - 1].size();j++) {
			temp = cnt[i - 1][j];
			for (int k = 0;k < 4;k++) {
				rx = temp / 1e3, ry = temp / 100 % 10, bx = temp / 10 % 10, by = temp % 10;
				int blue_result = blue_push(k);
				int red_result = red_push(k);
				if (blue_result == -1) continue;
				if (red_result == -1) {
					cout << i;
					return 0;
				}
				if (rx == bx && ry == by) {
					if (blue_result > red_result) bx -= dx[k], by -= dy[k];
					else rx -= dx[k], ry -= dy[k];
				}
				cnt[i].push_back(cal(rx, ry, bx, by));
			}
		}
	}

	cout << -1;
	return 0;
}