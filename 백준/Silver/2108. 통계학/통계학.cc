#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int x;
	double sum = 0;
	for (int i = 0;i < N;i++) {
		cin >> x;
		sum += x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int ans = v[0];
	int cnt = 1;
	int idx = 1;
	int num = 1;
	for (int i = 1;i < N;i++) {
		if (v[i] == v[i - 1]) num++;
		else num = 1;
		if (cnt < num) {
			ans = v[i];
			cnt = num;
			idx = 1;
		}
		else if (cnt == num && idx == 1) {
			ans = v[i];
			idx++;
		}
	}

	cout << (int)round(sum / N) << '\n';
	cout << v[N/2] << '\n';
	cout << ans << '\n';
	cout << v[N-1] - v[0] << '\n';
	
	return 0;
}