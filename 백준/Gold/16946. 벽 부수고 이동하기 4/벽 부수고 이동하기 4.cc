#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1010;
int n, m;
bool map[MAX][MAX];
int visited[MAX][MAX];
int groupSize[MAX * MAX];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y, int idx) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = idx;

	int cnt = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (map[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = idx;
				q.push({ nx,ny });
			}
		}
	}
	groupSize[idx] = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	// 외각을 편하게 두르기 위해 벽을 0, 공간을 1로 설정한다.
	for (int i = 1;i <= n;i++) {
		string s;
		cin >> s;
		for (int j = 1;j <= m;j++) {
			map[i][j] = !(s[j - 1] - '0');
		}
	}

	int idx = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (map[i][j] && !visited[i][j]) {
				bfs(i, j, idx);
				idx++;
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (map[i][j]) {
				cout << "0";
			}
			else {
				int ans = 1;
				int groups[4];
				int cnt = 0;

				for (int k = 0;k < 4;k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (map[nx][ny]) {
						int id = visited[nx][ny];
						bool check = true;
						for (int p = 0;p < cnt;p++) {
							if (groups[p] == id) {
								check = false;
								break;
							}
						}
						if (check) {
							groups[cnt++] = id;
							ans += groupSize[id];
						}
					}
				}
				cout << ans % 10;
			}
		}
		cout << "\n";
	}

	return 0;
}