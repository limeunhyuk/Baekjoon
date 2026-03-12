#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> len[32010];
queue<int> q;
int arr[32010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	int a, b;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		len[a].push_back(b);
		arr[b] += 1;
	}
	
	for (int i = 1;i <= n;i++) if (!arr[i]) q.push(i);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0;i < len[x].size();i++) {
			if (!--arr[len[x][i]]) q.push(len[x][i]);
		}
	}

	return 0;
}