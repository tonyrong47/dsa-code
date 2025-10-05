#include <iostream>
using namespace std;

void mul(int a[][2], int b[][3]) {
    int r[2][3];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            r[i][j] = 0;
            for (int k = 0; k < 2; k++) 
                r[i][j] += a[i][k] * b[k][j];
            cout << r[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int a[2][2] = {{1, 1}, {2, 2}};
    int b[2][3] = {{1, 1, 1}, {2, 2, 2}};
    mul(a, b);
    return 0;
}
