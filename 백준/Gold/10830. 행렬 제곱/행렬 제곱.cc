#include <iostream>
using namespace std;

int arr[38][6][6];
int ans[2][6][6];
int n;
long long int b;
bool idx;

void mul1(int e) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				arr[e][i][j] += arr[e - 1][i][k] * arr[e - 1][k][j];
				arr[e][i][j] %= 1000;
			}
		}
	}
}

void mul2(int x) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			ans[idx][i][j] = 0;
			for (int k = 0;k < n;k++) {
				ans[idx][i][j] += ans[!idx][i][k] * arr[x][k][j];
				ans[idx][i][j] %= 1000;
			}
		}
	}
	idx = !idx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> b;
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) cin >> arr[1][i][j];

	for (int i = 0;i < n;i++) {
		ans[1][i][i] = 1;
	}

	for (int i = 2;i < 38;i++) {
		mul1(i);
	}

	int i = 1;
	while (b) {
		int temp = b % 2;
		if (temp) mul2(i);
		i++;
		b /= 2;
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << ans[!idx][i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}