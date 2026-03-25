#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[4][4010];
vector<int> arr_plus1;
vector<int> arr_plus2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr_plus1.reserve(n * n);
	arr_plus2.reserve(n * n);
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 4;j++) {
			cin >> arr[j][i];
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			arr_plus1.push_back(arr[0][i] + arr[1][j]);
			arr_plus2.push_back(arr[2][i] + arr[3][j]);
		}
	}

	sort(arr_plus1.begin(), arr_plus1.end());
	sort(arr_plus2.begin(), arr_plus2.end());

	int idx1 = 0, idx2 = n * n - 1;
	long long int ans = 0;
	while (idx1 < n * n && idx2 >= 0) {
		int temp = arr_plus1[idx1] + arr_plus2[idx2];
		if (temp == 0) {
			int cnt1 = 0, cnt2 = 0;
			int val1 = arr_plus1[idx1], val2 = arr_plus2[idx2];
			while (idx1 < n * n && arr_plus1[idx1] == val1) { cnt1++; idx1++; }
			while (idx2 >= 0 && arr_plus2[idx2] == val2) { cnt2++; idx2--; }
			ans += (long long int) cnt1 * cnt2;
		}
		else {
			if (temp > 0) idx2--;
			else idx1++;
		}
	}
	cout << ans;

	return 0;
}