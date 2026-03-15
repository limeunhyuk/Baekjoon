#include <iostream>
using namespace std;

int n;
int num[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0;i < n;i++) cin >> num[i];

	int s = 0, e = n - 1;
	int ans = 2e9, ans1, ans2;
	while (s < e) {
		if (ans > abs(num[s] + num[e])) {
			ans = abs(num[s] + num[e]);
			ans1 = num[s];
			ans2 = num[e];
		}
		if (num[s] + num[e] > 0) e--;
		else s++;
	}

	cout << ans1 << " " << ans2;

	return 0;
}