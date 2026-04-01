#include <iostream>
#include <cstring>
using namespace std;

const int NMAX = 30010, MMAX = 100010;
int n, m, k;
int candy[NMAX];
int parent[NMAX];
int total_candy[NMAX];
int total_kid[NMAX];
int knapsack[2][NMAX];
bool flip;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unio(int a, int b) {
	int x = find(a);
	int y = find(b);
	parent[x] = y;
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
		total_candy[find(i)] += candy[i];
		total_kid[find(i)]++;
	}

	for (int i = 1;i <= n;i++) {
		if (total_candy[i]) {
			memset(knapsack[!flip], 0, sizeof(knapsack[!flip]));
			for (int j = 0;j < k;j++) {
				if (j - total_kid[i] >= 0 && knapsack[flip][j] < knapsack[flip][j - total_kid[i]] + total_candy[i]) {
					knapsack[!flip][j] = knapsack[flip][j - total_kid[i]] + total_candy[i];
				}
				if (knapsack[!flip][j] < knapsack[flip][j]) knapsack[!flip][j] = knapsack[flip][j];
			}
			flip = !flip;
		}
	}
	cout << knapsack[flip][k - 1];
	return 0;
}