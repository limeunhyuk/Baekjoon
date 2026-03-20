#include <iostream>
using namespace std;

int n;
int nlist[100010];
bool nexist[1000010];
int ans[1000010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> nlist[i];
		nexist[nlist[i]] = 1;
	}

	for (int i = 0;i < n;i++) {
		int x = nlist[i];
		for (int j = x * 2;j <= 1000000;j += x) {
			if (nexist[j]) {
				ans[j]--;
				ans[x]++;
			}
		}
	}

	for (int i = 0;i < n;i++) {
		int x = nlist[i];
		cout << ans[x] << " ";
	}

	return 0;
}