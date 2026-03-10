#include <iostream>
using namespace std;

int n;
int mi[2][3];
int ma[2][3];
int t[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> t[0] >> t[1] >> t[2];
		mi[1][0] = min(mi[0][0], mi[0][1]) + t[0];
		ma[1][0] = max(ma[0][0], ma[0][1]) + t[0];
		mi[1][1] = min(mi[0][0], min(mi[0][1], mi[0][2])) + t[1];
		ma[1][1] = max(ma[0][0], max(ma[0][1], ma[0][2])) + t[1];
		mi[1][2] = min(mi[0][1], mi[0][2]) + t[2];
		ma[1][2] = max(ma[0][1], ma[0][2]) + t[2];
		mi[0][0] = mi[1][0];
		ma[0][0] = ma[1][0];
		mi[0][1] = mi[1][1];
		ma[0][1] = ma[1][1];
		mi[0][2] = mi[1][2];
		ma[0][2] = ma[1][2];
	}

	cout << max(ma[1][0], max(ma[1][1], ma[1][2])) << " " << min(mi[1][0], min(mi[1][1], mi[1][2]));
	return 0;
}