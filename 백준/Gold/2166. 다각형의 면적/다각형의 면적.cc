#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int n;
long long int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	long long int x1, x2, y1, y2, x0, y0;
	cin >> x1 >> y1;
	x0 = x1, y0 = y1;
	for (int i = 1;i < n;i++) {
		cin >> x2 >> y2;
		ans += x1 * y2 - x2 * y1;
		x1 = x2, y1 = y2;
	}
	ans += x1 * y0 - x0 * y1;
	
	cout << fixed << setprecision(1) << abs((double)ans / 2);
	return 0;
}