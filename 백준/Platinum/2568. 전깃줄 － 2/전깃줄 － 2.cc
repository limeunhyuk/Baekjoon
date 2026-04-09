#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int lis[100010];
int pnt[500010];
bool check[500010];
int max_num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.reserve(n);
    for (int i = 0;i < n;i++) {
        v.push_back({ 0,0 });
        cin >> v[i].second >> v[i].first;
        if (max_num < v[i].second) max_num = v[i].second;
        check[v[i].second] = 1;
    }
    sort(v.begin(), v.end());
    
    int min_lines = 0;
    for (int i = 0;i < n;i++) {
        int temp = upper_bound(lis, lis + min_lines, v[i].second) - lis;
        lis[temp] = v[i].second;
        pnt[v[i].second] = temp + 1;
        if (min_lines < temp + 1) min_lines = temp + 1;
    }

    cout << n - min_lines << "\n";
    int temp = min_lines;
    for (int i = max_num;i > 0;i--) {
        while (pnt[i] != temp && i > 0) i--;
        check[i] = 0;
        temp--;
        if (temp == 0) break;
    }
    for (int i = 1;i <= max_num;i++) {
        if (check[i]) cout << i << "\n";
    }
    return 0;
}