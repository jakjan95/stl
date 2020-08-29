#include <algorithm>
#include <iostream>
#include <vector>

/*
Napisz funkcję Gather, która przyjmie std::vector<char> oraz spowoduje, że wszystkie wystąpienia * pojawią się w środku std::vector<char>.
Input: std::vector<char> vec {'*', '@', '*', '#', '@', '^', '*', '(', ')', '*'};
Output: @ # @ * * * * ^ ( )
*/

void Gather(std::vector<char>& vec, char ch) {
    //auto countChar = std::count(vec.begin(), vec.end(), ch);
    //auto middle = vec.begin() + ((vec.size() - 1) / 2) + (countChar - 1) / 2;

    auto pred{
        [&](auto& el) {
            return el != ch;
        }};

    auto middle = vec.begin() + vec.size()/2;
    std::stable_partition(vec.begin(), middle, pred);
    std::stable_partition(middle, vec.end(), [&](auto& el) { return !pred(el); });
}

template <typename T>
void PrintVec(const std::vector<T>& vec) {
    for (const auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<char> vec{'*', '@', '*', '#', '@', '^', '*', '(', ')', '*'};
    PrintVec(vec);
    Gather(vec, '*');
    PrintVec(vec);

    return 0;
}
