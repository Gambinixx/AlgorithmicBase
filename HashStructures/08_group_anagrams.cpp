#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using str = std::string;
using str_arr = std::vector<str>;
using str_matrix = std::vector<str_arr>;
using str_map = std::unordered_map<str, str_arr>;

str_matrix group_anagrams(const str_arr& strings) {
    // Создаем мапу где пары состоят из: ключ — отсортированная строка-анаграмма, значение — массив строк-анаграмм.
    str_map map;

    for (const str& s : strings) {
        str key = s;
        // Делаем уникальный ключ для каждой анаграммы
        std::sort(key.begin(), key.end());

        map[key].push_back(s);
    }

    str_matrix result;
    for (const auto& pair : map) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    str_arr input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    str_matrix grouped = group_anagrams(input);

    for (const auto& group : grouped) {

        std::cout << "[";
        for (const str& s : group) {
            std::cout << s << ", ";
        }
        std::cout << "]" << "\n";
    }

    return 0;
}