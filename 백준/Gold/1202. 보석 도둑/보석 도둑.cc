#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
pair<int, int> dia[300010];
int c[300010];
long long int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0;i < n;i++) cin >> dia[i].first >> dia[i].second;
	for (int i = 0;i < k;i++) cin >> c[i];

	sort(c, c + k);
	sort(dia, dia + n);

	priority_queue<int> pq;

	int idx = 0;
	for (int i = 0;i < k;i++) {
		while (dia[idx].first <= c[i] && idx < n) {
			pq.push(dia[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}