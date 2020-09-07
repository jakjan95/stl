#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
void printThree(const std::multimap<int, std::string> m) {
    std::vector<std::pair<int, std::string>> result;

    std::copy_if(m.begin(), m.end(), std::back_inserter(result), [](const auto& el) { return el.second.size() == 3; });
    std::for_each(result.cbegin(), result.cend(), [](const auto& el) {
        std::cout << el.second << '\n';
    });
}

int main() {
    std::multimap<int, std::string> values;

    values.insert({5, "Ala"});
    values.insert({5, "Ma"});
    values.insert({5, "Kota"});
    values.insert({5, "A"});
    values.insert({5, "Kot"});
    values.insert({5, "Ma"});
    values.insert({5, "Ale"});

    printThree(values);
}
