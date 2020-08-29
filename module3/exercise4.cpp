#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

/*

Napisz funkcję GetVec(size_t count), która zwróci std::vector<int> z wartościami od 10 do 10 + n, inkrementując je co 1. 
Następnie napisz drugą funkcję int Multiply(std::vector<int> vec), która zwróci wartość równą iloczynowi każdego elementu std::vector<int>.

Input: GetVec(7)

Output: {10, 11, 12, 13, 14, 15, 16}

Input: Multiply(vec)

Output: 57657600

*/

std::vector<int> GetVec(size_t count) {
    std::vector<int> vec(count);
    std::iota(vec.begin(), vec.end(), 10);
    return vec;
}

int Multiply(std::vector<int> vec) {
    int product = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
    return product;
}

template <typename T>
void PrintVec(const std::vector<T>& vec) {
    for (const auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec = GetVec(7);
    PrintVec(vec);
    std::cout << Multiply(vec) << '\n';
    return 0;
}
