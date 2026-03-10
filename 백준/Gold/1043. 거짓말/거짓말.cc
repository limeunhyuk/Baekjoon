#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, t, temp, tt;
vector<int> pn[51];
vector<int> np[51];
queue<int> q;
bool pt[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> t;
	for (int i = 0;i < t;i++) {
		cin >> temp;
		pt[temp] = 1;
		q.push(temp);
	}
	for (int i = 0;i < m;i++) {
		cin >> t;
		for (int j = 0;j < t;j++) {
			cin >> temp;
			pn[i].push_back(temp);
			np[temp].push_back(i);
		}
	}

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		for (int i = 0;i < np[temp].size();i++) {
			t = np[temp][i];
			for (int j = 0;j < pn[t].size();j++) {
				tt = pn[t][j];
				if (!pt[tt]) {
					pt[tt] = 1;
					q.push(tt);
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0;i < m;i++) {
		bool ch = 1;
		for (int j = 0;j < pn[i].size();j++) {
			t = pn[i][j];
			if (pt[t]) {
				ch = 0;
				break;
			}
		}
		ans += ch;
	}
	cout << ans;
	return 0;
}