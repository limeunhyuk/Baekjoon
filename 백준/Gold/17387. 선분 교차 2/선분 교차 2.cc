#include <iostream>
using namespace std;

long long int x[5];
long long int y[5];
pair<long long int, long long int> comp[5];
bool ans;

int ccw(int i1, int i2, int i3) {
	long long int temp = x[i1] * y[i2] + x[i2] * y[i3] + x[i3] * y[i1] - x[i2] * y[i1] - x[i3] * y[i2] - x[i1] * y[i3];
	if (temp > 0) return 1;
	if (temp < 0) return -1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 1;i <= 4;i++) {
		cin >> x[i] >> y[i];
		comp[i] = { x[i],y[i] };
	}
	int check1 = ccw(1, 2, 3) * ccw(1, 2, 4);
	int check2 = ccw(3, 4, 1) * ccw(3, 4, 2);
	
	if (!check1 && !check2) {
		if (comp[1] > comp[2]) swap(comp[1], comp[2]);
		if (comp[3] > comp[4]) swap(comp[3], comp[4]);
		if (comp[1] <= comp[4] && comp[3] <= comp[2]) ans = 1;
	}
	else if (check1 <= 0 and check2 <= 0) ans = 1;

	cout << ans;

	return 0;
}