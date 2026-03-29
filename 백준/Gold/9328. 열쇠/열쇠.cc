#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const int MAX = 110;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		int h, w;
		cin >> h >> w;

		char map[MAX][MAX];
		queue<pair<int, int>> visit;
		vector<pair<int, int>> keyLoca[26];
		bool haveKey[26];
		bool visited[MAX][MAX];

		// 테스트케이스 변수 초기화
		memset(haveKey, 0, sizeof(haveKey));
		memset(visited, 0, sizeof(visited));
		memset(map, '.', sizeof(map));
		
		for (int i = 1;i <= h;i++) {
			string s;
			cin >> s;
			for (int j = 1;j <= w;j++) {
				map[i][j] = s[j - 1];
			}
		}

		string s;
		cin >> s;
		if (s != "0") for (char i : s) haveKey[i - 'a'] = 1;

		visit.push({ 0,0 });
		visited[0][0] = 1;

		int ans = 0;
		while (!visit.empty()) {
			pair<int, int> cur = visit.front();
			visit.pop();
			int curX = cur.first;
			int curY = cur.second;

			for (int i = 0;i < 4;i++) {
				int nX = curX + dx[i];
				int nY = curY + dy[i];

				if (0 <= nX && nX <= h + 1 && 0 <= nY && nY <= w + 1) {
					if (map[nX][nY] == '*' || visited[nX][nY]) continue;

					char c = map[nX][nY];
					visited[nX][nY] = 1;

					if ('A' <= c && c <= 'Z') {
						if (!haveKey[c - 'A']) {
							keyLoca[c - 'A'].push_back({ nX,nY });
							continue;
						}
					}
					else if ('a' <= c && c <= 'z') {
						haveKey[c - 'a'] = 1;
						for (auto i : keyLoca[c - 'a']) {
							visit.push({ i.first,i.second });
						}
						keyLoca[c - 'a'].clear();
					}
					else if (c == '$') ans++;

					visit.push({ nX, nY });
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}