#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int A = 1e6;

int main() {

    // Запоминаем все простые числа до 10^6 заполняя решето Эратосфена
    vector<int> primes;
    vector<bool> is_prime(A + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= A; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (int j = i + i; j <= A; j+=i) {
            is_prime[j] = false;
        }
    }

    // Заранее считаем в какой части должно быть число
    vector<int> part(A + 1, 1);
    for (int i = 1; i <= A; i++) {
        if (part[i] == 1) {
            for (int prime : primes) {
                if (i * prime > A) break;
                part[i * prime] = 2;
            }
        }
    }   

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int num : nums) cout << part[num] << " ";
}
