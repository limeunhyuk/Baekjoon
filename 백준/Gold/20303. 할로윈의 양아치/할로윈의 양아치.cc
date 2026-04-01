#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int NMAX = 30010, MMAX = 100010;
int n, m, k;
int candy[NMAX];
int parent[NMAX];
int total_candy[NMAX];
int total_kid[NMAX];
int knapsack[NMAX];

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unio(int a, int b) {
	int x = find(a);
	int y = find(b);
	if(x != y) parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) {
		cin >> candy[i];
		parent[i] = i;
	}

	for (int i = 1;i <= m;i++) {
		int a, b;
		cin >> a >> b;
		unio(a, b);
	}

	for (int i = 1;i <= n;i++) {
		int root = find(i);
		total_candy[root] += candy[i];
		total_kid[root]++;
	}

	for (int i = 1;i <= n;i++) {
		if (find(i) == i) {
			int weight = total_kid[i];
			int value = total_candy[i];
			for (int j = k - 1;j >= weight;j--) {
				knapsack[j] = max(knapsack[j], knapsack[j - weight] + value);
			}
		}
	}
	cout << knapsack[k - 1];
	return 0;
}