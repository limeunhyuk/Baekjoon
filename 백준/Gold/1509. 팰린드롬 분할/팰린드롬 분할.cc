#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 2510;
char arr[MAX];
bool isPal[MAX][MAX];
int minPal[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0;i < len;i++) arr[i + 1] = s[i];

	// 팰린드롬 여부 저장
	for (int j = 1;j <= len;j++) isPal[j][j] = 1;
	for (int j = 1;j < len;j++) if (arr[j] == arr[j + 1]) isPal[j][j + 1] = 1;
	for (int i = 2;i < len;i++) {
		for (int j = 1;j <= len - i;j++) {
			if (arr[j] == arr[j + i] && isPal[j + 1][j + i - 1]) isPal[j][j + i] = 1;
		}
	}
	
	minPal[1] = 1;
	for (int i = 2;i <= len;i++) {
		char c = s[i];
		minPal[i] = minPal[i - 1] + 1;
		for (int j = 1;j < i;j++) {
			if (isPal[j][i]) minPal[i] = min(minPal[i], minPal[j - 1] + 1);
		}
	}

	cout << minPal[len];

	return 0;
}