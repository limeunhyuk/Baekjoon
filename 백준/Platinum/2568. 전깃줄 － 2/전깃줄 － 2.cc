#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int lis[100010];
int lis_loca[500010];
bool check[500010];
int max_num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.reserve(n);
    for (int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        // A 기준으로 출력하기 위해 바꿔서 넣는다.
        v.emplace_back(b, a);
        if (max_num < a) max_num = a;
        check[a] = 1;
    }
    sort(v.begin(), v.end());
    
    int min_lines = 0;
    for (int i = 0;i < n;i++) {
        int temp = lower_bound(lis, lis + min_lines, v[i].second) - lis;
        lis[temp] = v[i].second;
        lis_loca[v[i].second] = temp + 1;
        if (min_lines < temp + 1) min_lines = temp + 1;
    }

    cout << n - min_lines << "\n";
    int temp = min_lines;
    for (int i = max_num;i > 0;i--) {
        while (lis_loca[i] != temp && i > 0) i--;
        check[i] = 0;
        temp--;
        if (temp == 0) break;
    }
    for (int i = 1;i <= max_num;i++) {
        if (check[i]) cout << i << "\n";
    }
    return 0;
}