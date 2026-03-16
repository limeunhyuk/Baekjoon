#include <iostream>
#include <algorithm>
using namespace std;

int n;
int liq[5010];
long long int ans = 4e9;
int ansn[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0;i < n;i++) cin >> liq[i];
	sort(liq, liq + n);

	for (int i = 0;i < n - 2;i++) {
		int s = i + 1, e = n - 1;
		while (s < e) {
			long long int temp = (long long) liq[s] + liq[i] + liq[e];
			if (temp == 0) {
				cout << liq[i] << " " << liq[s] << " " << liq[e];
				return 0;
			}
			if (ans > abs(temp)) {
				ans = abs(temp);
				ansn[0] = liq[i], ansn[1] = liq[s], ansn[2] = liq[e];
			}
			if (temp > 0) e--;
			else s++;
		}
	}

	cout << ansn[0] << " " << ansn[1] << " " << ansn[2];
	return 0;
}