#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
long long N;

struct Matrix {
    long long v[2][2];

    Matrix() { memset(v, 0, sizeof(v)); }

    Matrix operator*(const Matrix& B) const {
        Matrix A;
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 2;j++) {
                for (int k = 0;k < 2;k++) {
                    A.v[i][j] = (A.v[i][j] + v[i][k] * B.v[k][j]) % MOD;
                }
            }
        }
        return A;
    }
};

Matrix matmul(Matrix a, long long n) {
    Matrix ans;
    for (int i = 0;i < 2;i++) ans.v[i][i] = 1;

    while (n) {
        if (n % 2) ans = ans * a;
        a = a * a;
        n /= 2;
    }

    return ans;
}

long long board[2][2] = {
    { 1,1 },
    { 1,0 }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    Matrix mat;
    memcpy(mat.v, board, sizeof(board));

    Matrix ans = matmul(mat, N);

    cout << ans.v[1][0];
    
    return 0;
}