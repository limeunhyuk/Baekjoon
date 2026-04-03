#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	cout << stoi(s1) + stoi(s2) - stoi(s3) << "\n";
	cout << stoi(s1 + s2) - stoi(s3);

	return 0;
}