#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> e;
int n, m;
long long int ans;
int parent[100010];

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
	if (find(a) != find(b)) parent[parent[b]] = parent[a];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	int a, b, c;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		e.push_back({ c,{a,b} });
	}

	for (int i = 1;i <= n;i++) parent[i] = i;
	sort(e.begin(), e.end());

	int cnt = 2, idx = 0;
	while (cnt < n) {
		int new_len = e[idx].first;
		int new_a = e[idx].second.first;
		int new_b = e[idx].second.second;
		if (find(new_a) != find(new_b)) {
			ans += new_len;
			cnt++;
			uni(new_a, new_b);
		}
		idx++;
	}
	
	cout << ans;
	return 0;
}