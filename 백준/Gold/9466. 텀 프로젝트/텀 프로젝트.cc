#include <iostream>
#include <vector>
using namespace std;

int T, n;
int point[100010];
int visit[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> point[i];
			visit[i] = 0;
		}
		int idx = 1;
		for (int i = 1;i <= n;i++) {
			if (visit[i]) {
				continue;
			}
			int start_idx = idx;
			visit[i] = idx++;
			int j = point[i];
			while (!visit[j]) {
				visit[j] = idx++;
				j = point[j];
			}
			if (visit[j] >= start_idx) ans += visit[j] - start_idx;
			else ans += idx - start_idx;
		}
		cout << ans << "\n";
	}
	
	return 0;
}