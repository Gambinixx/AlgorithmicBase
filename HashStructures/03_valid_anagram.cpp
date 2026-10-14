#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using ch_multiset = std::unordered_multiset<char>;
using str = std::string;
using vec = std::vector<char>;

bool valid_anagram(str s1, str s2) {
    // СНачала проверим длину: у двух анаграм длина всегда одинакова
    if (s1.length() != s2.length()) return false;

    // объявляем контейнеры
    ch_multiset mult;
    vec debug_set;

    // Проходим по первой строке и заполняем сет
    for (char ch : s1) {
        mult.insert(ch);

        debug_set.assign(mult.begin(), mult.end());
    }

    // проходим по второй строке и находим совпадения с литералами из сета
    for (char ch : s2) {
        if (mult.count(ch) == 0) return false;

        auto it = mult.find(ch); // итератор на узел в списке коллизий

        mult.erase(it); // очищаем

        debug_set.assign(mult.begin(), mult.end());
    
    }

    return mult.empty();
}

int main() {
    str s1 = "anagram";
    str s2 = "nagaram";

    str t1 = "rat";
    str t2 = "car";     // Должно быть: False

    std::cout << "Test 1 (anagram/nagaram): " << (valid_anagram(s1, s2) ? "Valid" : "Invalid") << std::endl;
    std::cout << "Test 2 (rat/car):         " << (valid_anagram(t1, t2) ? "Valid" : "Invalid") << std::endl;

    return 0;
}