#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

string len1;
string len2;
string len3;
int lcs[1010][1010];

void flcs(int i, int j) {
	if (i == 0 || j == 0) return;
	else if (lcs[i][j] == lcs[i][j - 1]) flcs(i, j - 1);
	else if (lcs[i][j] == lcs[i - 1][j]) flcs(i - 1, j);
	else {
		len3 = len1[i - 1] + len3;
		flcs(i - 1, j - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> len1 >> len2;
	len3 = "";
	int n = len1.length();
	int m = len2.length();

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (len1[i - 1] == len2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
		}
	}
	
	cout << lcs[n][m] << '\n';
	if (lcs[n][m] != 0) {
		flcs(n, m);
		cout << len3;
	}
	return 0;
}