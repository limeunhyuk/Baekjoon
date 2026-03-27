#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
int g, p;
int i;
int maxGate[MAX];
int parent[MAX];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unio(int a, int b) {
	int x = find(a);
	int y = find(b);
	parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g >> p;

	for (i = 0;i < p;i++) cin >> maxGate[i];
	for (i = 1;i <= g;i++) parent[i] = i;

	for (i = 0;i < p;i++) {
		int curGate = find(maxGate[i]);
		if (curGate == 0) break;
		unio(curGate, curGate - 1);
	}

	cout << i;

	return 0;
}