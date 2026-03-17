#include <iostream>
#include <algorithm>
using namespace std;

int n;
int seq_max[1000010];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	int x;
	cin >> x;
	seq_max[1] = x;
	ans = 1;
	for (int i = 1;i < n;i++) {
		cin >> x;
		int y = lower_bound(seq_max + 1, seq_max + ans + 1, x) - seq_max;
		seq_max[y] = x;
		if (y > ans) ans = y;
	}
	
	cout << ans;
	return 0;
}