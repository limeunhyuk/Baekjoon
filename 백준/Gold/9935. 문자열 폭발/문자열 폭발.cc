#include <iostream>
#include <string>
using namespace std;

string s1, s2, s;
bool bomb;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s1 >> s2;
	int len = s2.length();

	for (int i = 0;i < s1.size();i++) {
		s += s1[i];
		if (s.length() >= len) {
			bomb = 1;
			for (int j = 0;j < len;j++) {
				if (s[s.length() - len + j] != s2[j]) {
					bomb = 0;
					break;
				}
			}
			if (bomb) s.erase(s.end() - len, s.end());
		}
	}

	if (s.size()) cout << s;
	else cout << "FRULA";

	return 0;
}