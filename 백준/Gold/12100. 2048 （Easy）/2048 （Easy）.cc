#include <iostream>
#include <cstring>
using namespace std;

int n;

struct board
{
	int map[20][20];
};

int answer;

board moveup(board Board) {
	board ans;
	memset(ans.map, 0, sizeof(ans.map));
	for (int j = 0;j < n;j++) {
		int num1 = 0;
		int pnt = 0;
		for (int i = 0;i < n;i++) {
			int num2 = Board.map[i][j];
			if (num2) {
				if (num1 == num2) {
					ans.map[pnt++][j] = num1 + 1;
					if (answer < num1 + 1) answer = num1 + 1;
					num1 = 0;
				}
				else {
					if (num1) ans.map[pnt++][j] = num1;
					num1 = num2;
				}
			}
			ans.map[pnt][j] = num1;
		}
	}
	return ans;
}
board rotate(board Board) {
	board ans;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			ans.map[i][j] = Board.map[j][n - 1 - i];
		}
	}
	return ans;
}

void move(int cnt, board Board) {
	if (cnt == 5) return;	
	move(cnt + 1, moveup(Board));
	Board = rotate(Board);
	move(cnt + 1, moveup(Board));
	Board = rotate(Board);
	move(cnt + 1, moveup(Board));
	Board = rotate(Board);
	move(cnt + 1, moveup(Board));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	board Board;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			int temp;
			cin >> temp;
			int num_digit = 0;
			while (temp > 1) {
				temp >>= 1;
				num_digit++;
			}
			Board.map[i][j] = num_digit;
			if (answer < num_digit) answer = num_digit;
		}
	}
	
	move(0, Board);

	cout << (1 << answer);

	return 0;
}