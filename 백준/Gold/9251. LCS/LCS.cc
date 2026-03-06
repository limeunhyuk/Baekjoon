#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

char len1[1010];
char len2[1010];
int lcs[1010][1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> len1 >> len2;
	int n = strlen(len1);
	int m = strlen(len2);

	for (int i = 0;i <= n;i++) {
		for (int j = 0;j <= m;j++) {
			if (i == 0 or j == 0) lcs[i][j] = 0;
			else if (len1[i - 1] == len2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
		}
	}
	
	cout << lcs[n][m];

	return 0;
}