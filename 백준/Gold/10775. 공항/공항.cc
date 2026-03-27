#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
int g, p;
int maxGate;
int parent[MAX];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g >> p;
	for (int i = 1;i <= g;i++) parent[i] = i;

	int ans = 0;
	for (int i = 0;i < p;i++) {
		cin >> maxGate;
		int curGate = find(maxGate);
		if (curGate == 0) break;
		parent[curGate] = find(curGate - 1);
		ans++;
	}

	cout << ans;

	return 0;
}