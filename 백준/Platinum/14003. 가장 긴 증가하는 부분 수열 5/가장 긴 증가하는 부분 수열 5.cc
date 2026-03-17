#include <iostream>
#include <vector>
using namespace std;

int n, maxl = 1;
int seq_list[1000010];
int seq_max[1000010];
int seq_idx[1000010];
int ans[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	cin >> seq_list[0];
	seq_max[1] = seq_list[0];
	seq_idx[0] = 1;
	for (int i = 1;i < n;i++) {
		cin >> seq_list[i];
		int s = 1, e = maxl;
		while (s <= e) {
			int t = (s + e) / 2;
			if (seq_max[t] < seq_list[i]) s = t + 1;
			else e = t - 1;
		}

		seq_max[s] = seq_list[i];
		seq_idx[i] = s;
		if (maxl < s) maxl = s;
	}
	
	int temp = maxl;
	cout << maxl << "\n";
	for (int i = n - 1;i >= 0;i--) {
		if (seq_idx[i] == temp) {
			temp--;
			ans[temp] = seq_list[i];
		}
	}

	for (int i = 0;i < maxl;i++) {
		cout << ans[i] << " ";
	}

	return 0;
}