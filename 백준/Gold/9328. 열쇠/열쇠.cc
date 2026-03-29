#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;
int t;
int h, w;
string map[MAX];
queue<pair<int, int>> visit;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool haveKey[26];
bool visited[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> h >> w;

		// 테스트케이스 변수 초기화
		vector<pair<int, int>> keyLoca[26];
		for (int i = 0;i < 26;i++) haveKey[i] = 0;
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				visited[i][j] = 0;
			}
		}
		
		for (int i = 0;i < h;i++) {
			cin >> map[i];
			// 최초 진입 가능 지점 확인
			if (i == 0 || i == h - 1) {
				for (int j = 0;j < w;j++) {
					if (map[i][j] != '*') {
						visit.push({ i,j });
						visited[i][j] = 1;
					}
				}
			}
			else {
				if (map[i][0] != '*') {
					visit.push({ i,0 });
					visited[i][0] = 1;
				}
				if (map[i][w - 1] != '*') {
					visit.push({ i,w - 1 });
					visited[i][w - 1] = 1;
				}
			}
		}

		string s;
		cin >> s;
		if (s != "0") for (char i : s) haveKey[i - 'a'] = 1;

		int ans = 0;
		while (!visit.empty()) {
			pair<int, int> cur = visit.front();
			visit.pop();
			int curX = cur.first;
			int curY = cur.second;
			char c = map[curX][curY];
			
			if ('A' <= c && c <= 'Z') {
				if (!haveKey[c - 'A']) {
					keyLoca[c - 'A'].push_back({ curX,curY });
					continue;
				}
			}
			if ('a' <= c && c <= 'z') {
				haveKey[c - 'a'] = 1;
				for (auto i : keyLoca[c - 'a']) {
					visit.push({ i.first,i.second });
				}
			}
			if (c == '$') ans++;

			map[curX][curY] = '*';
			for (int i = 0;i < 4;i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (0 <= nextX && nextX < h && 0 <= nextY && nextY < w) {
					if (map[nextX][nextY] != '*' && !visited[nextX][nextY]) {
						visit.push({ nextX, nextY });
						visited[nextX][nextY] = 1;
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}