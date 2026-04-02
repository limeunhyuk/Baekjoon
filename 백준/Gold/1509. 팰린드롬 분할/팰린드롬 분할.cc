#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 2510;
bool isPal[MAX][MAX];
int minPal[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	int len = s.length();
	s = " " + s;

	for (int j = 1;j <= len;j++) isPal[j][j] = 1;
	for (int j = 1;j < len;j++) if (s[j] == s[j + 1]) isPal[j][j + 1] = 1;
	for (int i = 2;i < len;i++) {
		for (int j = 1;j <= len - i;j++) {
			if (s[j] == s[j + i] && isPal[j + 1][j + i - 1]) isPal[j][j + i] = 1;
		}
	}
	
	for (int i = 1;i <= len;i++) {
		minPal[i] = minPal[i - 1] + 1;
		for (int j = 1;j < i;j++) {
			if (isPal[j][i]) minPal[i] = min(minPal[i], minPal[j - 1] + 1);
		}
	}

	cout << minPal[len];

	return 0;
}