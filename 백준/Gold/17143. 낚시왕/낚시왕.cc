#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 105;
int R, C, M;

struct Shark {
    int r, c, speed, dir, size;
    bool dead;
};

Shark sharks[10010];
int map[MAX][MAX];
long long ans = 0;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

inline int turn(int d) {
    if (d == 1) return 2;
    if (d == 2) return 1;
    if (d == 3) return 4;
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].speed >> sharks[i].dir >> sharks[i].size;
        sharks[i].dead = false;
        map[sharks[i].r][sharks[i].c] = i;
    }

    for (int col = 1; col <= C; col++) {
        for (int row = 1; row <= R; row++) {
            if (map[row][col]) {
                int idx = map[row][col];
                ans += sharks[idx].size;
                sharks[idx].dead = true;
                break;
            }
        }

        memset(map, 0, sizeof(map));

        for (int i = 1; i <= M; i++) {
            if (sharks[i].dead) continue;

            int speed = sharks[i].speed;
            int dir = sharks[i].dir;
            int r = sharks[i].r;
            int c = sharks[i].c;

            if (dir == 1 || dir == 2) {
                int move = speed % ((R - 1) * 2);
                while (move--) {
                    r += dx[dir];
                    if (r < 1) { r = 2; dir = turn(dir); }
                    else if (r > R) { r = R - 1; dir = turn(dir); }
                }
            }
            else {
                int move = speed % ((C - 1) * 2);
                while (move--) {
                    c += dy[dir];
                    if (c < 1) { c = 2; dir = turn(dir); }
                    else if (c > C) { c = C - 1; dir = turn(dir); }
                }
            }

            sharks[i].r = r;
            sharks[i].c = c;
            sharks[i].dir = dir;

            if (map[r][c]) {
                int target = map[r][c];
                if (sharks[target].size < sharks[i].size) {
                    sharks[target].dead = true;
                    map[r][c] = i;
                }
                else {
                    sharks[i].dead = true;
                }
            }
            else {
                map[r][c] = i;
            }
        }
    }

    cout << ans;
    return 0;
}