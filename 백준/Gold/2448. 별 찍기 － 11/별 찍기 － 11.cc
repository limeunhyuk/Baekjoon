#include <iostream>
using namespace std;

int n;
bool map[3100][6200];

void star(int m, int x, int y) {
	if (m == 3) {
		map[x][y] = 1;
		map[x + 1][y - 1] = 1; map[x + 1][y + 1] = 1;
		for (int i = -2;i < 3;i++) map[x + 2][y + i] = 1;
		return;
	}
	star(m / 2, x, y);
	star(m / 2, x + m / 2, y - m / 2);
	star(m / 2, x + m / 2, y + m / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	star(n, 0, n - 1);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n * 2 - 1;j++) {
			if (map[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}

	return 0;
}