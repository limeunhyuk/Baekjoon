#include <iostream>
using namespace std;

int n, s;
int arr[100010];
int ans = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> s;
	for (int i = 0;i < n;i++) cin >> arr[i];
	
	int a = -1, b = -1;
	while (b < n) {
		if (s > 0) s -= arr[++b];
		else {
			if (ans > b - a) ans = b - a;
			s += arr[++a];
		}
	}

	if (ans == 1e9) ans = 0;
	cout << ans;
	return 0;
}