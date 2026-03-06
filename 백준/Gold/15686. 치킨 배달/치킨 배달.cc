#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int n, m;
int map[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chick;
bool check[13];
int ans = 1e9;

void cal() {
	int ans2 = 0;
	int ans3 = 1e9;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (check[j]) {
				ans3 = min(ans3, abs(home[i].first - chick[j].first) + abs(home[i].second - chick[j].second));
			}
		}
		ans2 += ans3;
		ans3 = 1e9;
	}
	ans = min(ans, ans2);
}

void choose(int cnt, int idx) {
	if (cnt == M) {
		cal();
		return;
	}
	if (idx == m) return;
	check[idx] = 1;
	choose(cnt + 1, idx + 1);
	check[idx] = 0;
	choose(cnt, idx + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) home.push_back({ i,j });
			else if (map[i][j] == 2) chick.push_back({ i,j });
		}
	}

	n = home.size(), m = chick.size();

	choose(0, 0);

	cout << ans;
	
	return 0;
}