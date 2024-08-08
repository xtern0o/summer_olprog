#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

    int a_i = n, b_i = m * n * (n - 1) + n, c_i = (-1) * m * n * (1 + m * n) / 2;
    int D_i = b_i * b_i - 4 * a_i * c_i;

    double i = ((-1) * b_i + pow(D_i, 0.5)) / 2 / a_i;
    int i_1 = floor(i), i_2 = ceil(i);

    int diff_i1 = abs(a_i * i_1 * i_1 + b_i * i_1 + c_i);
    int diff_i2 = abs(a_i * i_2 * i_2 + b_i * i_2 + c_i);

    int v = (diff_i1 < diff_i2) ? i_1 : i_2;

    
    int a_j = 2 * m, b_j = m * (m + 1) - m + 1, c_j = (-1) * (1 + m * n) * m * n;
    int D_j = b_j * b_j - 4 * a_j * c_j;

    double j = ((-1) * b_j + pow(D_j, 0.5)) / 2 / a_j;
    int j_1 = floor(j), j_2 = ceil(j);

    int diff_j1 = abs(a_j * j_1 * j_1 + b_j * j_1 + c_j);
    int diff_j2 = abs(a_j * j_2 * j_2 + b_j * j_2 + c_j);

    int h = (diff_j1 < diff_j2) ? j_1 : j_2;

    if (min(diff_i1, diff_i2) < min(diff_j1, diff_j2)) {
        cout << "V " << v + 1;
    }
    else cout << "H "<< h + 1;

    cout << endl;

    }
    
    
}