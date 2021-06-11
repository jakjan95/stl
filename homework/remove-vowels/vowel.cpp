#include "vowel.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>

void removeVowels(std::vector<std::string>& words)
{
    constexpr std::array<char, 6> vowels = { 'a', 'e', 'i', 'o', 'u', 'y' };

    auto is_vowel = [&vowels](char character) {
        return std::find(vowels.begin(), vowels.end(), std::tolower(character)) != vowels.end();
    };

    auto remove_vowel = [&](std::string& word) {
        word.erase(std::remove_if(word.begin(), word.end(), is_vowel), word.end());
    };

    std::for_each(words.begin(), words.end(), remove_vowel);
}
