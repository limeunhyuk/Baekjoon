#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

using State = pair<int, vector<int>>;

struct swapCmd {
    int l, r, c;
};

int N, M;
vector<int> arr;
map<vector<int>, int> m;
vector<swapCmd> sw;
priority_queue<State, vector<State>, greater<State>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.resize(N);
    for (int i = 0;i < N;i++) {
        cin >> arr[i];
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
        auto [cost, curarr] = pq.top();
        pq.pop();

        if (m[curarr] < cost) continue;

        for (swapCmd cmd : sw) {
            swap(curarr[cmd.l - 1], curarr[cmd.r - 1]);
            if (m.find(curarr) == m.end() || m[curarr] > cost + cmd.c) {
                m[curarr] = cost + cmd.c;
                pq.push({ cost + cmd.c, curarr });
            }
            swap(curarr[cmd.l - 1], curarr[cmd.r - 1]);
        }
    }

    sort(arr.begin(), arr.end());
    if (m.find(arr) == m.end()) cout << -1;
    else cout << m[arr];

    return 0;
}