#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long

using namespace std;

const map<int, vector<int>> h = {
    {1, {8, 6}},
    {2, {9, 7}},
    {3, {4, 8}},
    {4, {9, 3, 0}},
    {5, {}},
    {6, {7, 1, 0}},
    {7, {2, 6}},
    {8, {1, 3}},
    {9, {2, 4}},
    {0, {6, 4}}
};


// k - длина последовательностей, p - позиция, с которой набираются номера
ll f(int k, int p) {
    if (p == 5) return 0;

    if (k == 1) return h.at(p).size();

    vector<int> nums = h.at(p);
    ll res = 0;
    for (int num : nums) {
        res += f(k - 1, num);
    }
}


int main() {
    int n; cin >> n;

}