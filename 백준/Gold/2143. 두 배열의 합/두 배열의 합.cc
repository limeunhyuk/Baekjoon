#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e3 + 10;
int t, n, m;
int nlist[MAX];
int mlist[MAX];
vector<int> nsum;
vector<int> msum;
long long int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	
	cin >> n;
	nsum.reserve(n * (n + 1) / 2);

	for (int i = 0;i < n;i++) cin >> nlist[i];
	for (int i = 0;i < n;i++) {
		int sum = 0;
		for (int j = i;j < n;j++) {
			sum += nlist[j];
			nsum.push_back(sum);
		}
	}
	sort(nsum.begin(), nsum.end());

	cin >> m;
	msum.reserve(m * (m + 1) / 2);

	for (int i = 0;i < m;i++) cin >> mlist[i];
	for (int i = 0;i < m;i++) {
		int sum = 0;
		for (int j = i;j < m;j++) {
			sum += mlist[j];
			msum.push_back(sum);
		}
	}
	sort(msum.begin(), msum.end());

	int nidx = 0, midx = msum.size() - 1;
	int nsize = nsum.size();

	while (nidx < nsize && midx >= 0) {
		int temp = nsum[nidx] + msum[midx];
		if (temp == t) {
			int ncnt = 0, mcnt = 0;
			int nval = nsum[nidx], mval = msum[midx];
			
			while (nidx < nsize && nsum[nidx] == nval) {
				ncnt++;
				nidx++;
			}
			while (midx >= 0 && msum[midx] == mval) {
				mcnt++;
				midx--;
			}
			ans += (long long int) ncnt * mcnt;
		}
		else {
			if (temp > t) midx--;
			else nidx++;
		}
	}
	
	cout << ans;

	return 0;
}