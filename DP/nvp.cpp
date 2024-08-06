#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> d(n, 1);
    vector<int> p(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (d[j] + 1 > d[i]) {
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] > ans) {
            pos = i;
            ans = d[i];
        }
    }

    vector<int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = p[pos];
    }
    reverse(path.begin(), path.end());
    for (int i : path) cout << a[i] << " ";
}