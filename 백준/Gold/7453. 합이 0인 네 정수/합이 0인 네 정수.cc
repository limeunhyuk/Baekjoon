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

	sort(arr_plus2.begin(), arr_plus2.end());

	long long int ans = 0;
	for (int val: arr_plus1) {
		int temp = -val;
		int cnt = upper_bound(arr_plus2.begin(), arr_plus2.end(), temp) - lower_bound(arr_plus2.begin(), arr_plus2.end(), temp);
		ans += cnt;
	}
	cout << ans;

	return 0;
}