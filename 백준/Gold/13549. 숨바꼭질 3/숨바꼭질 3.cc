#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define inf 1e9

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool v[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	pq.push({ 0,n });
	while (!pq.empty()) {
		int t = pq.top().first;
		int s = pq.top().second;
		pq.pop();

		if (k == s) {
			cout << t;
			return 0;
		}

		if (v[s]) continue;
		v[s] = 1;
		if (s * 2 < k + 2) pq.push({ t, s * 2 });
		if (s - 1 >= 0) pq.push({ t + 1, s - 1 });
		if (s + 1 < k + 2) pq.push({ t + 1, s + 1 });
		
	}
	
	return 0;
}