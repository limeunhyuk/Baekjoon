#include <iostream>
#include <string>
using namespace std;

int n, m;
char dir[1010][1010];
int visited[1010][1010];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < m;j++) dir[i][j] = s[j];
	}

	int idx = 1;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (visited[i][j]) continue;
			int x = i, y = j;
			while (!visited[x][y]) {
				visited[x][y] = idx;
				int temp = 0;
				char c = dir[x][y];
				switch (c) {
				case 'D': temp = 0; break;
				case 'U': temp = 1; break;
				case 'R': temp = 2; break;
				case 'L': temp = 3; break;
				}
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