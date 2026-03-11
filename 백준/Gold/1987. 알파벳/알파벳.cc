#include <iostream>
#include <string>
using namespace std;

int r, c;
string s;
int map[22][22];
bool visit[30];
int dx[4] = { 1, -1, 0,0 };
int dy[4] = { 0, 0, 1,-1 };
int ans;

void dfs(int x, int y, int l) {
	if (visit[map[x][y]]) return;
	if (ans < l) ans = l;
	visit[map[x][y]] = 1;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r and ny >= 0 && ny < c) dfs(nx, ny, l + 1);
	}
	visit[map[x][y]] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0;i < r;i++) {
		cin >> s;
		for (int j = 0;j < c;j++) {
			map[i][j] = s[j] - 'A';
		}
	}

	dfs(0, 0, 1);
	cout << ans;
	return 0;
}