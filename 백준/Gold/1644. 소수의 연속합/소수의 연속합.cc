#include <iostream>
#include <vector>
using namespace std;

int n, sum, ans;
bool arr[4000010];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	int i;
	for (i = 2;i * i <= n;i++) {
		if (arr[i]) continue;
		for (int j = i * i; j <= n;j += i) arr[j] = 1;
	}
	for (i = 2;i <= n;i++) if (!arr[i]) v.push_back(i);

	int a = 0, b = 0;
	while (1) {
		if (sum >= n) {
			if (sum == n) ans++;
			sum -= v[a++];
		}
		else if (b == v.size()) break;
		else sum += v[b++];
	}

	cout << ans;
	return 0;
}