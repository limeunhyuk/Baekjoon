#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t, n, k, w;
vector<int> adj[100010];
int deg[100010];
int tim[100010];
int max_tim[100010];
int a, b, y;
pair<long long int, int> x;
long long int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n >> k;

		for (int i = 1;i <= n;i++) {
			cin >> a;
			tim[i] = a;
			max_tim[i] = 0;
			deg[i] = 0;
			adj[i].clear();
		}

		for (int i = 0;i < k;i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			deg[b]++;
		}

		cin >> w;

		queue<pair<long long int, int>> q;
		for (int i = 1;i <= n;i++) if (!deg[i]) q.push({ tim[i],i });

		while (!q.empty()) {
			x = q.front();
			if (x.second == w) {
				cout << x.first << "\n";
				break;
			}
			q.pop();
			for (int i = 0;i < adj[x.second].size();i++) {
				y = adj[x.second][i];
				if (max_tim[y] < x.first) max_tim[y] = x.first;
				if (!--deg[y]) q.push({ tim[y] + max_tim[y],y});
			}
		}
	}

	return 0;
}