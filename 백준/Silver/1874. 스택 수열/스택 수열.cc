#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
stack<int> s;
vector<char> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	s.push(0);
	int x;
	int idx = 1;
	for (int i = 0;i < n;i++) {
		cin >> x;
		if (x > s.top()) {
			for (idx; idx <= x;idx++) {
				s.push(idx);
				ans.push_back('+');
			}
			s.pop();
			ans.push_back('-');
		}
		else {
			int y = s.top();
			if (y == x) {
				s.pop();
				ans.push_back('-');
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	
	for (int i = 0;i < ans.size();i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}