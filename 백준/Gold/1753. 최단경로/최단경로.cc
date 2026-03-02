#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1E9

int V, E, K;
vector<pair<int, int>> len[20010];
int ans[20010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> V >> E >> K;

  for (int i = 1; i <= V; i++) {
    ans[i] = INF;
  }

  int u, v, w;
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    len[u].emplace_back(make_pair(v, w));
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      dij;
  dij.push(make_pair(0, K));

  ans[K] = 0;
  while (!dij.empty()) {
    int cost = dij.top().first;
    int now = dij.top().second;
    dij.pop();

    if (ans[now] < cost) continue;

    for (auto i : len[now]) {
      if (cost + i.second < ans[i.first]) {
        ans[i.first] = cost + i.second;
        dij.push(make_pair(cost + i.second, i.first));
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if (ans[i] == INF) {
      cout << "INF" << '\n';
    } else {
      cout << ans[i] << '\n';
    }
  }

  return 0;
}