#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int max_n = 1000;
vector<int> adj[max_n + 10];
vector<int> ans;
int in_degree[max_n + 10];

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
			adj[idx1].push_back(idx2);
			in_degree[idx2]++;
			idx1 = idx2;
		}
	}

	queue<int> q;
	for (int i = 1;i <= n;i++) if (!in_degree[i]) q.push(i);

	// 위상정렬
	while (!q.empty()) {
		int cur_n = q.front();
		ans.push_back(cur_n);
		q.pop();
		for (int next_n : adj[cur_n]) {
			in_degree[next_n]--;
			if (in_degree[next_n] == 0) q.push(next_n);
		}
	}
	// 만약 결과가 n개가 아닌 경우는 안에서 사이클 발생이라는 의미
	if (ans.size() == n) for (int i = 0;i < n;i++) cout << ans[i] << "\n";
	else cout << 0;

	return 0;
}