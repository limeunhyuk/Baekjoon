#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int year;
vector<pair<int, int>> ice_loca;
int ice[301][301];
int melt[301][301];
int visit[301][301];

void dfs(int x, int y) {
  visit[x][y] = year;
  if (ice[x - 1][y] && visit[x - 1][y] != year) dfs(x - 1, y);
  if (ice[x + 1][y] && visit[x + 1][y] != year) dfs(x + 1, y);
  if (ice[x][y - 1] && visit[x][y - 1] != year) dfs(x, y - 1);
  if (ice[x][y + 1] && visit[x][y + 1] != year) dfs(x, y + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> ice[i][j];
      if (ice[i][j]) ice_loca.emplace_back(i, j);
    }
  }
  year = 1;

  while (!ice_loca.empty()) {
    dfs(ice_loca[0].first, ice_loca[0].second);
    for (const auto& i : ice_loca) {
      if (visit[i.first][i.second] != year) {
        cout << year - 1;
        return 0;
      }
    }

    for (const auto& i : ice_loca) {
      int x = i.first;
      int y = i.second;
      melt[x][y] =
          !ice[x - 1][y] + !ice[x + 1][y] + !ice[x][y - 1] + !ice[x][y + 1];
    }

    vector<pair<int, int>> ice_loca_next;
    for (const auto& i : ice_loca) {
      int x = i.first;
      int y = i.second;
      ice[x][y] -= min(melt[x][y], ice[x][y]);
      if (ice[x][y]) ice_loca_next.emplace_back(x, y);
    }
    ice_loca = ice_loca_next;

    year++;
  }

  if (ice_loca.empty()) year = 0;

  cout << year;

  return 0;
}