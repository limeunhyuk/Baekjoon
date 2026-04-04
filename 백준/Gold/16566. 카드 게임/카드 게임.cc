#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 4000010;
int card[MAX];
int parent[MAX];

int n, m, k;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++) {
		cin >> card[i];
		parent[i] = i;
	}
	parent[m] = m;
	sort(card, card + m );

	for (int i = 0;i < k;i++) {
		int temp;
		cin >> temp;
		int idx = find(upper_bound(card, card + m, temp) - card);
		cout << card[idx] << "\n";
		parent[idx] = find(idx + 1);
	}

	return 0;
}