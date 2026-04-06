#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, vector<int>> Arr;
typedef tuple<int, int, int> Arr2;

int N, M;
vector<int> arr;
map<vector<int>, int> m;
vector<Arr2> sw;
priority_queue<Arr, vector<Arr>, greater<Arr>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0;i < N;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cin >> M;
    for (int i = 0;i < M;i++) {
        int l, r, c;
        cin >> l >> r >> c;
        sw.push_back({ l,r,c });
    }

    pq.push({ 0,arr });
    m[arr] = 0;
    while (!pq.empty()) {
        auto temp = pq.top();
        int cost = temp.first;
        vector<int> curarr = temp.second;
        pq.pop();

        for (Arr2 curfunc : sw) {
            int l = get<0>(curfunc);
            int r = get<1>(curfunc);
            int c = get<2>(curfunc);
            swap(curarr[l - 1], curarr[r - 1]);
            if (m.find(curarr) == m.end() || m[curarr] > cost + c) {
                m[curarr] = cost + c;
                pq.push({ cost + c, curarr });
            }
            swap(curarr[l - 1], curarr[r - 1]);
        }
    }

    sort(arr.begin(), arr.end());
    if (m.find(arr) == m.end()) cout << -1;
    else cout << m[arr];

    return 0;
}