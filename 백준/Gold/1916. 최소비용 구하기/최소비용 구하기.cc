#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9

int n, m;
int s, d, e;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
vector<pair<int, int>> v[1010];
int visit[1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1;i <= n;i++) {
		visit[i] = INF;
	}

	for (int i = 0;i < m;i++) {
		cin >> s >> e >> d;
		v[s].push_back({ d,e });
	}
	cin >> s >> e;

	visit[s] = 0;
	pq.push({ 0,s });

	int dd, ss;
	while (!pq.empty()) {
		dd = pq.top().first;
		ss = pq.top().second;
		pq.pop();

		if (visit[ss] < dd) continue;
		for (int i = 0;i < v[ss].size();i++) {
			int x = v[ss][i].first;
			int y = v[ss][i].second;
			if (dd + x < visit[y]) {
				visit[y] = dd + x;
				pq.push({ visit[y], y });
			}
		}
	}

	cout << visit[e];
	return 0;
}