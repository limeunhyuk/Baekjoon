#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> info[10010];
bool visit[10010];
int v, e;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> v >> e;

	int a, b, c;
	for (int i = 0;i < e;i++) {
		cin >> a >> b >> c;
		info[a].push_back({ c,b });
		info[b].push_back({ c,a });
	}

	visit[1] = 1;
	for (int i = 0;i < info[1].size();i++) {
		pq.push(info[1][i]);
	}

	while (!pq.empty()) {
		int new_len = pq.top().first;
		int new_ver = pq.top().second;
		pq.pop();

		if (visit[new_ver]) continue;
		ans += new_len;
		visit[new_ver] = 1;
		for (int i = 0;i < info[new_ver].size();i++) {
			pq.push(info[new_ver][i]);
		}
	}
	
	cout << ans;
	return 0;
}