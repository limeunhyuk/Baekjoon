#include <iostream>
using namespace std;

int n, m;
int parent[500010];
int ans;

int find(int i) {
	if (parent[i] == i) return i;
	return parent[i] = find(parent[i]);
}

bool unio(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x == y) return 1;
	parent[x] = y;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0;i < n;i++) parent[i] = i;
	for (int i = 1;i <= m;i++) {
		int x, y;
		cin >> x >> y;
		if (unio(x, y) && !ans) ans = i;
	}

	cout << ans;
	return 0;
}