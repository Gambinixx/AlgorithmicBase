#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstddef>

using vec = std::vector<int>;
using int_set = std::unordered_set<int>;
using s_t = std::size_t;

void remove_dupl(vec& arr) {
    int_set seen;
    vec debug_set;
    s_t unique_zone = 0;

    // Идем по массиву слева направо, ищем дубликаты, добавляем в сет, перезаписываем уникальную зону
    for (s_t i = 0; i < arr.size(); i++) {
        if (seen.count(arr[i]) == 0) {
            seen.insert(arr[i]);

            debug_set.assign(seen.begin(), seen.end());

            arr[unique_zone] = arr[i];

            unique_zone++;
        }
    }
    arr.resize(unique_zone);
}

int main() {
    // Исходный хаос дубликатов. Чистых уникальных чисел тут всего 4: {5, 2, 8, 1}
    vec arr = {5, 2, 5, 8, 2, 1, 8, 5};

    std::cout << "Before filter: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    remove_dupl(arr);

    std::cout << "After filter, unique nums:  ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}