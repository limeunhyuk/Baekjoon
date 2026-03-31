#include <iostream>
#include <cstring>
#include <set>
using namespace std;

const int MAX = 1010;
int n, m;
bool map[MAX][MAX];
int visited[MAX][MAX];
int groupSize[MAX * MAX];
int idx, cnt;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y) {
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] && !visited[nx][ny]) {
			cnt++;
			visited[nx][ny] = idx;
			dfs(nx, ny);
		}
	}
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

	idx = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (map[i][j] && !visited[i][j]) {
				cnt = 1;
				visited[i][j] = idx;
				dfs(i, j);
				groupSize[idx] = cnt;
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
				set<int> s;
				for (int k = 0;k < 4;k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (map[nx][ny]) s.insert(visited[nx][ny]);
				}
				for (int temp : s) ans += groupSize[temp];
				cout << ans % 10;
			}
		}
		cout << "\n";
	}

	return 0;
}