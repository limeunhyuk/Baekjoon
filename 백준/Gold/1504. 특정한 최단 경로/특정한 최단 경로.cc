#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define inf 1e9

int n, e, v1, v2;
vector<pair<int, int>> v[810];
int visit[810];
int final[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> e;
	
	int a, b, c;
	for (int i = 0;i < e;i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}

	cin >> v1 >> v2;
	pair<int, int> p[5] = { {1,v1},{1,v2},{v1,v2},{v1,n},{v2,n} };

	for (int i = 0;i < 5;i++) {
		for (int j = 1;j <= n;j++) visit[j] = inf;
		int start = p[i].first, end = p[i].second;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0,start });
		visit[start] = 0;

		while (!pq.empty()) {
			int dis = pq.top().first;
			int poi = pq.top().second;
			pq.pop();

			if (visit[poi] < dis) continue;
			for (int j = 0;j < v[poi].size();j++) {
				int new_dis = v[poi][j].first;
				int new_poi = v[poi][j].second;
				if (dis + new_dis < visit[new_poi]) {
					visit[new_poi] = dis + new_dis;
					pq.push({ visit[new_poi], new_poi });
				}
			}
		}
		final[i] = visit[end];
	}
	
	bool check = 0;
	if (final[0] != inf && final[2] != inf && final[4] != inf) check = 1;
	if (final[1] != inf && final[2] != inf && final[3] != inf) check = 1;

	if (check) cout << min(final[0] + final[2] + final[4], final[1] + final[2] + final[3]);
	else cout << -1;

	return 0;
}