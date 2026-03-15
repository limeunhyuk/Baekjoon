#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int comp_t;
int loca[100010][3];
vector<int> v;
vector<pair<int, pair<int, int>>> krus;
int parent[100010];
long long int ans;

bool compare(int a, int b) {
	return loca[a][comp_t] < loca[b][comp_t];
}

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void unio(int a, int b) {
	int new_a = find(a);
	int new_b = find(b);
	if(new_a != new_b) parent[new_a] = new_b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> loca[i][0] >> loca[i][1] >> loca[i][2];
		v.push_back(i);
		parent[i] = i;
	}

	for (int i = 0;i < 3;i++) {
		comp_t = i;
		sort(v.begin(), v.end(), compare);
		for (int j = 1;j < n;j++) {
			int pla1 = v[j - 1], pla2 = v[j];
			krus.push_back({ abs(loca[pla1][i] - loca[pla2][i]), {pla1, pla2} });
		}
	}
	
	sort(krus.begin(), krus.end());
	for (int i = 0;i < krus.size();i++) {
		int len = krus[i].first;
		int pla1 = krus[i].second.first;
		int pla2 = krus[i].second.second;
		
		if (find(pla1) == find(pla2)) continue;
		ans += len;
		unio(pla1, pla2);
	}

	cout << ans;

	return 0;
}