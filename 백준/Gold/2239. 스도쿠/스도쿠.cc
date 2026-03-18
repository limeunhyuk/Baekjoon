#include <iostream>
using namespace std;

int map[11][11];
int hor[10];
int ver[10];
int sqr[4][4];

bool canput(int k, int i, int j) {
	if (hor[i] & (1 << k)) return 0;
	if (ver[j] & (1 << k)) return 0;
	if (sqr[i / 3][j / 3] & (1 << k)) return 0;
	return 1;
}

void dfs(int idx) {
	int i = idx / 9;
	int j = idx % 9;
	if (idx == 81) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}
	if (map[i][j]) dfs(idx + 1);
	else {
		for (int k = 1;k <= 9;k++) {
			if (canput(k, i, j)) {
				map[i][j] = k;
				hor[i] += 1 << k;
				ver[j] += 1 << k;
				sqr[i / 3][j / 3] += 1 << k;
				dfs(idx + 1);
				map[i][j] = 0;
				hor[i] -= 1 << k;
				ver[j] -= 1 << k;
				sqr[i / 3][j / 3] -= 1 << k;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> c;
			int x = c - '0';
			if (x) {
				map[i][j] = x;
				hor[i] += 1 << x;
				ver[j] += 1 << x;
				sqr[i / 3][j / 3] += 1 << x;
			}
		}
	}

	dfs(0);

	return 0;
}