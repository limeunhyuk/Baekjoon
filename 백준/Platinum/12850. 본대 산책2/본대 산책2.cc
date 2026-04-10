#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
long long D;

struct Matrix {
    long long v[8][8];

    Matrix() { memset(v, 0, sizeof(v)); }

    Matrix operator*(const Matrix& B) const {
        Matrix A;
        for (int i = 0;i < 8;i++) {
            for (int j = 0;j < 8;j++) {
                for (int k = 0;k < 8;k++) {
                    A.v[i][j] = (A.v[i][j] + v[i][k] * B.v[k][j]) % MOD;
                }
            }
        }
        return A;
    }
};

Matrix matmul(Matrix a, long long d) {
    Matrix ans;
    for (int i = 0;i < 8;i++) ans.v[i][i] = 1;

    while (d) {
        if (d % 2) ans = ans * a;
        a = a * a;
        d /= 2;
    }

    return ans;
}

long long board[8][8] = {
    { 0,1,1,0,0,0,0,0 },
    { 1,0,1,1,0,0,0,0 },
    { 1,1,0,1,1,0,0,0 },
    { 0,1,1,0,1,1,0,0 },
    { 0,0,1,1,0,1,1,0 },
    { 0,0,0,1,1,0,0,1 },
    { 0,0,0,0,1,0,0,1 },
    { 0,0,0,0,0,1,1,0 }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D;

    Matrix mat;
    memcpy(mat.v, board, sizeof(board));

    Matrix ans = matmul(mat, D);

    cout << ans.v[0][0];
    
    return 0;
}