#include <iostream>
using namespace std;

long long num_one(long long x) {
	if (x == 0) return 0;
	if (x == 1) return 1;
	long long ans = 0;
	long long num_digit = 0;
	long long temp = x;

	while (temp > 1) {
		temp >>= 1;
		num_digit++;
	}

	ans += num_digit * (1LL << (num_digit - 1)) + 1;
	x -= (1LL << num_digit);
	ans += x;
	ans += num_one(x);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	cin >> a >> b;

	cout << num_one(b) - num_one(a - 1);

	return 0;
}