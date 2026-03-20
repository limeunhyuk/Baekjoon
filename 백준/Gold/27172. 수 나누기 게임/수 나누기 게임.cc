#include <iostream>
using namespace std;

const int MAX = 1e6;
int n;
int nmaximum;
int nlist[100010];
bool nexist[MAX + 10];
int ans[MAX + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> nlist[i];
		nexist[nlist[i]] = 1;
		if (nmaximum < nlist[i]) nmaximum = nlist[i];
	}

	for (int i = 0;i < n;i++) {
		int x = nlist[i];
		for (int j = x * 2;j <= nmaximum;j += x) {
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