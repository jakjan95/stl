#include <algorithm>
#include <iostream>
#include <vector>
/*
    Napisz funkcję, która przyjmie dwa std::vector<int> oraz zmienną int. 
    Pierwszy std::vector<int> zawiera kontener na którym operujemy, drugi zawiera wartości jakie chcemy przenieść, 
    a wartość int to numer indexu, na który chcemy przenieść wartości.
    void ChangePos(std::vector<int>& vec, const std::vector<int>& values, int position)
*/

void ChangePos(std::vector<int>& vec, const std::vector<int>& values, int position) {
    auto pred{
        [&](auto& el) {
            return std::find(values.begin(), values.end(), el) == values.end();
        }};

    auto middle = vec.begin() + position + values.size() - 1;

    std::stable_partition(vec.begin(), middle, pred);
    std::stable_partition(middle, vec.end(), [&](auto& el) { return !pred(el); });
}

void PrintVec(const std::vector<int>& vec) {
    for (const auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintVec(vec);
    ChangePos(vec, {1, 3, 9}, 4);
    PrintVec(vec);

    return 0;
}
