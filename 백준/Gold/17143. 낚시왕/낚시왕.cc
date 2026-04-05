#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int lenMAX = 110, arrMAX = 10010;
int r, c, m;
int shark[arrMAX][6];
int sharkloca[lenMAX][lenMAX];
long long ans;

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> m;

	for (int i = 1;i <= m;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> shark[i][j];
		}
		sharkloca[shark[i][0]][shark[i][1]] = i;
	}

	for (int i = 1;i <= c;i++) {
		for (int j = 1;j <= r;j++) {
			int temp = sharkloca[j][i];
			if (temp && !shark[temp][5]) {
				ans += shark[temp][4];
				shark[temp][5] = 1;
				break;
			}
		}

		memset(sharkloca, 0, sizeof(sharkloca));

		for (int j = 1;j <= m;j++) {
			if (!shark[j][5]) {
				if (shark[j][3] < 3) {
					int move_x = (shark[j][2]) % (2 * r - 2);
					while (move_x--) {
						shark[j][0] += dx[shark[j][3]];
						if (shark[j][0] == 0) {
							shark[j][0] = 2;
							shark[j][3] += 2 * (shark[j][3] % 2) - 1;
						}
						else if (shark[j][0] == r + 1) {
							shark[j][0] = r - 1;
							shark[j][3] += 2 * (shark[j][3] % 2) - 1;
						}
					}
				}
				else {
					int move_y = (shark[j][2]) % (2 * c - 2);
					while (move_y--) {
						shark[j][1] += dy[shark[j][3]];
						if (shark[j][1] == 0) {
							shark[j][1] = 2;
							shark[j][3] += 2 * (shark[j][3] % 2) - 1;
						}
						else if (shark[j][1] == c + 1) {
							shark[j][1] = c - 1;
							shark[j][3] += 2 * (shark[j][3] % 2) - 1;
						}
					}
				}
				int new_x = shark[j][0];
				int new_y = shark[j][1];
				int idx = sharkloca[new_x][new_y];
				if (idx && shark[idx][4] > shark[j][4]) shark[j][5] = 1;
				else {
					shark[idx][5] = 1;
					sharkloca[new_x][new_y] = j;
				}
			}
		}
	}

	cout << ans;

	return 0;
}