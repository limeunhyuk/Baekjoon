#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int n;
int loca[MAX];
int inorder[MAX];
int postorder[MAX];

void dfs(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e) return;
	int idx = loca[postorder[post_e]];
	cout << postorder[post_e] << " ";
	dfs(in_s, idx - 1, post_s, post_s + idx - 1 - in_s);
	dfs(idx + 1, in_e, post_s + idx - in_s, post_e - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> inorder[i];
		loca[inorder[i]] = i;
	}
	for (int i = 0;i < n;i++) cin >> postorder[i];

	dfs(0, n - 1, 0, n - 1);

	return 0;
}