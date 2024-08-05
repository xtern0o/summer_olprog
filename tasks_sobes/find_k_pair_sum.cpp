// Найти в отсортированном массиве пару, значение которой равно k. Сложность: O(N)

#include <iostream>
#include <vector>


using namespace std;


pair<int, int> find_pair_k_sum(vector<int> &a, int k) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        if (a[l] + a[r] == k) return {a[l], a[r]};

        if (a[l] + a[r] < k) l++;
        else r--;
    }
    return {0, 0};
}


int main() {
    vector<int> a = {-9, -5, -2, -1, 1, 4, 9, 11};
    pair<int, int> p = find_pair_k_sum(a, 3);
    cout << p.first << " " << p.second;
}