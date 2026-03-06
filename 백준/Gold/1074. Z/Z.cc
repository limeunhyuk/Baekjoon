#include <algorithm>
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> r >> c;

	int ans = 0;
	while (N > 0) {
		int k = pow(2, N - 1);
		ans += (2 * int(r / k) + int(c / k)) * k * k;
		r %= k;
		c %= k;
		N--;
	}

	cout << ans;
	
	return 0;
}