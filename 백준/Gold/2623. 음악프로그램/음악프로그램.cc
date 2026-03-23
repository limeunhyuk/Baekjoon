#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int max_n = 1000;
vector<int> v[max_n + 10];
vector<int> ans;
int cnt[max_n + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	ans.reserve(n);

	for (int i = 0;i < m;i++) {
		int k;
		cin >> k;
		int idx1, idx2;
		cin >> idx1;
		for (int j = 1;j < k;j++) {
			cin >> idx2;
			v[idx1].push_back(idx2);
			cnt[idx2]++;
			idx1 = idx2;
		}
	}

	queue<int> q;
	for (int i = 1;i <= n;i++) if (!cnt[i]) q.push(i);

	while (!q.empty()) {
		int cur_n = q.front();
		ans.push_back(cur_n);
		q.pop();
		for (int i = 0;i < v[cur_n].size();i++) {
			int next_n = v[cur_n][i];
			cnt[next_n]--;
			if (cnt[next_n] == 0) q.push(next_n);
		}
	}
	if (ans.size() == n) for (int i = 0;i < n;i++) cout << ans[i] << "\n";
	else cout << 0;

	return 0;
}