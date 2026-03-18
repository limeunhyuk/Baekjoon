#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100010];
int n, r, q;
int num_node[100010];

int dfs(int node_now, int node_bef) {
	if (node_now != r && v[node_now].size() == 1 && v[node_now][0] == node_bef) return num_node[node_now] = 1;
	int ans = 1;
	for (int i = 0;i < v[node_now].size();i++) {
		if(v[node_now][i] != node_bef) ans += dfs(v[node_now][i], node_now);
	}
	return num_node[node_now] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> r >> q;
	for (int i = 1;i < n;i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(r, 0);
	for (int i = 0;i < q;i++) {
		int x;
		cin >> x;
		cout << num_node[x] << "\n";
	}

	return 0;
}