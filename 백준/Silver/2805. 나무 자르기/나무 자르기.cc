#include <iostream>
#include <vector>
using namespace std;

long long int N, M;
long long int H[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < N;i++) cin >> H[i];

	long long int s = 0, e = 1000000001;
	while (s <= e) {
		long long int t = (s + e) / 2;
		long long int sum = 0;
		for (int i = 0;i < N;i++) sum += max(H[i] - t, (long long int) 0);
		if (sum >= M) s = t + 1;
		else e = t - 1;
	}
	cout << e;

	return 0;
}