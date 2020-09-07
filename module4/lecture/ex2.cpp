#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

/*
    Stwórz std::unordered_map<int, std::string> oraz std::multiset<int>
    Wypełnij je dowolnymi wartościami
    Usuń jeden z elementów,
    dodaj dodatkowy element
    Usuń elementy, według wymyślonego przez Ciebie predykatu.
*/

template <typename Container>
void print(const Container& c) {
    std::cout << "SET:";
    for (auto el : c) {
        std::cout << el << '\t';
    }
    std::cout << '\n';
}

template <typename Container>
void printMap(const Container& c) {
    std::cout << "KEY | VALUE\n";
    for (auto el : c) {
        std::cout << el.first << '\t' << el.second << '\n';
    }
}

int main() {
    std::unordered_map<int, std::string> map1{{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {6, "six"}};

    printMap(map1);
    map1.erase(3);
    printMap(map1);

    map1.insert({9, "nine"});
    printMap(map1);

    for (auto it = map1.begin(); it != map1.end();) {
        if ((*it).first % 3 == 0) {
            it = map1.erase(it);
        } else {
            it++;
        }
    }

    printMap(map1);


    std::multiset<int> mset{1, 1, 4, 3, 0, 0, 5};

    print(mset);
    mset.insert(15);
    print(mset);

    mset.erase(4);
    print(mset);

    for (auto it = mset.begin(); it != mset.end();) {
        if (*it % 3 == 0) {
            it = mset.erase(it);
        } else {
            it++;
        }
    }

    return 0;
}
