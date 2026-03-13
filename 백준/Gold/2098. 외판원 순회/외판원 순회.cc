#include <iostream>
#include <cstring>
using namespace std;
#define inf 1e9

int n;
int len[16][16];
int dist[16][1 << 17];

int tsp(int loca, int visit) {
	if (visit == (1 << n) - 1) {
		if (len[loca][0]) return len[loca][0];
		return inf;
	}

	if (dist[loca][visit] != -1) return dist[loca][visit];
	dist[loca][visit] = inf;

	for (int i = 0;i < n;i++) {
		if (!(visit & (1 << i)) && len[loca][i]) {
			int j = tsp(i, visit | (1 << i));
			if (dist[loca][visit] > len[loca][i] + j) dist[loca][visit] = len[loca][i] + j;
		}
	}
	return dist[loca][visit];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> len[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));

	cout << tsp(0, 1);

	return 0;
}