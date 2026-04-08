#include <iostream>
#include <algorithm>
using namespace std;

using Deca = pair<int, int>;

const int MAX = 3010;
int n;
Deca loca[MAX][2];
int parent[MAX];
int groups[MAX];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unio(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x != y) parent[x] = y;
}

int ccw(Deca a, Deca b, Deca c) {
    long long temp = a.first * b.second + b.first * c.second + c.first * a.second;
    temp -= a.second * b.first + b.second * c.first + c.second * a.first;
    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

bool isconnect(int a, int b) {
    int check1 = ccw(loca[a][0], loca[a][1], loca[b][0]) * ccw(loca[a][0], loca[a][1], loca[b][1]);
    int check2 = ccw(loca[b][0], loca[b][1], loca[a][0]) * ccw(loca[b][0], loca[b][1], loca[a][1]);
    if (!check1 && !check2) {
        if (loca[a][0] > loca[a][1]) swap(loca[a][0], loca[a][1]);
        if (loca[b][0] > loca[b][1]) swap(loca[b][0], loca[b][1]);
        return (loca[a][0] <= loca[b][1] && loca[b][0] <= loca[a][1]);
    }
    return (check1 <= 0 && check2 <= 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1;i <= n;i++) parent[i] = i;

    for (int i = 1;i <= n;i++) {
        cin >> loca[i][0].first >> loca[i][0].second >> loca[i][1].first >> loca[i][1].second;
        for (int j = 1;j < i;j++) {
            if (find(j) != find(i)) {
                if (isconnect(i, j)) {
                    unio(i, j);
                }
            }
        }
    }
    
    int numgroups = 0, numlines = 0;
    for (int i = 1;i <= n;i++) {
        int temp = find(i);
        if (!groups[temp]) numgroups++;
        groups[temp]++;
        if (numlines < groups[temp]) numlines = groups[temp];
    }

    cout << numgroups << "\n" << numlines;

    return 0;
}