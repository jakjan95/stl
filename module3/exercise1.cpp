#include <algorithm>
#include <iostream>
#include <vector>

bool fun(std::vector<int>& vec, int value, int new_pos) {
    if (new_pos >= vec.size()) {
        return false;
    }

    auto val = std::find(vec.begin(), vec.end(), value);
    if (val == vec.end()) {
        return false;
    }
    auto newPos = std::next(vec.begin(), new_pos - 1);

    auto valDistance = std::distance(vec.begin(), val);
    auto newPosDistance = std::distance(vec.begin(), newPos);

    if (newPosDistance > valDistance) {
        std::rotate(val, val + 1, newPos + 1);
    } else {
        std::rotate(newPos, val, val + 1);
    }
    return true;
}

void print(const std::vector<int>& v) {
    for (auto el : v) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(v);

    fun(v, 7, 1);
    print(v);

    fun(v, 7, 7);
    print(v);

    fun(v, 1, 1);
    print(v);

    fun(v, 9, 1);
    print(v);

    fun(v, 9, 2);
    print(v);

    return 0;
}
