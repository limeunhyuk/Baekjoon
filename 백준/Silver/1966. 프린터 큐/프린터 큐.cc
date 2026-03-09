#include <iostream>
#include <vector>
using namespace std;

int T, N, M;
int pri[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		int x;
		vector<int> doc;

		for (int i = 0;i < 10;i++) pri[i] = 0;

		for (int i = 0;i < N;i++) {
			cin >> x;
			doc.push_back(x);
			pri[x]++;
		}

		int idx = 0;
		int ans = 0;
		for (int i = 9;i > doc[M];i--) {
			if (pri[i]) do { idx = (idx + N - 1) % N; } while (doc[idx] != i);
			ans += pri[i];
		}
		while (idx != M) {
			if (doc[idx] == doc[M]) ans++;
			idx = (idx + 1) % N;
		}
		ans++;
		cout << ans << '\n';
	}

	return 0;
}