#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;


int main() {
    int t; cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n, m; cin >> n >> m;

        double i = (-2 + pow(4 + 2 * (pow(m, 2) + m - 2), 0.5)) / 2;
        int i1 = floor(i);
        int i2 = ceil(i);
        
        int diff_i1 = abs((i1 + 1) * (i1 + 2) / 2 - (i1 + m + 1) * (m - 1) / 2);
        int diff_i2 = abs((i2 + 1) * (i2 + 2) / 2 - (i2 + m + 1) * (m - 1) / 2);

        int h = diff_i1 < diff_i2 ? i1 + 1 : i2 + 1;

        int a = 1;
        int b = - 2 * m + n + m * n + 3;
        int c = - (m * n * n - m * n + 2 * n);
        
        int D = b * b - 4 * a * c;
        double j = (-b + pow(D, 0.5)) / 2 / a;

        int j1 = floor(j);
        int j2 = ceil(j);

        int diff_j1 = (1 + m * (j1 - 1)) * j1;
        int diff_j2 = (j2 + 1 + m * (n - 1) + 1) * (n - j2);

        int v = diff_j1 < diff_j2 ? j1 + 1 : j2 + 1;

        if (min(diff_j1, diff_j2) < min(diff_i1, diff_i2)) cout << "V " << v;
        else cout << "H " << h;

        cout << endl;
    }
    
}