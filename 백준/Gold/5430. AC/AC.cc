#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int t, n;
string p, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--) {
		deque<int> dq;
		cin >> p >> n >> s;
		s = s.substr(1, s.length() - 2);

		if (!s.empty()) {
			stringstream ss(s);
			string temp;
			while (getline(ss, temp, ',')) dq.push_back(stoi(temp));
		}

		bool arr = 0;
		bool err = 0;
		for (int i = 0;i < p.length();i++) {
			if (p[i] == 'R') arr = !arr;
			else {
				if (dq.size() == 0) {
					cout << "error" << "\n";
					err = 1;
					break;
				}
				if (arr) dq.pop_back();
				else dq.pop_front();
			}
		}
		if (!err) {
			if (dq.empty()) {
				cout << "[]\n";
				continue;
			}
			cout << '[';
			if (arr) {
				for (int i = dq.size() - 1;i > 0;i--) cout << dq[i] << ',';
				cout << dq[0];
			}
			else {
				for (int i = 0;i < dq.size() - 1;i++) cout << dq[i] << ',';
				cout << dq[dq.size() - 1];
			}
			cout << ']' << "\n";
		}
	}
	return 0;
}