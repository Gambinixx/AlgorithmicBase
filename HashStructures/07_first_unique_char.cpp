#include <iostream>
#include <cstddef>
#include <string>
#include <unordered_map>

using s_t = std::size_t;

int first_unique_char(const std::string& s) {
    std::unordered_map<char, int> freq;

    for (char ch : s) {
        freq[ch]++;
    }

    for (s_t i = 0; i < s.length(); ++i) { // Находим уникальное вхождение
        if (freq[s[i]] == 1) return static_cast<int>(i);
    }

    return -1;
}

int main() {
    std::string s1 = "leetcode";
    std::string s2 = "loveleetcode";
    std::string s3 = "aabb";

    std::cout << "Test 1 ('leetcode'): index " << first_unique_char(s1) << "\n";
    std::cout << "Test 2 ('loveleetcode'): index " << first_unique_char(s2) << "\n";
    std::cout << "Test 3 ('aabb'): index " << first_unique_char(s3) << "\n";

    return 0;
}