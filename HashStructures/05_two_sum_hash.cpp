#include <iostream>
#include <utility> // для pair();
#include <cstddef>
#include <vector>
#include <unordered_map>

using vec = std::vector<int>;
using s_t = std::size_t;
using hash_map = std::unordered_map<int, s_t>;
using indx_pair = std::pair<s_t, s_t>;

indx_pair two_sum_map(const vec& arr, int target) {
    hash_map seen;

    // Перебираем массив: ищем complement в хэш-мапе, а если не находим — сохраняем текущий элемент и его индекс.
    for (s_t i = 0; i < arr.size(); i++) {
        int current = arr[i];
        int complement = target - current; // Недостающее число к сумме таргет;

        auto it = seen.find(complement);

        if (it != seen.end()) { // Если итератор не равен end(), значит ключ найден
            return indx_pair{it->second, i}; // Индекс элемента лежащий по ключу в мапе, плюс текущий индекс — это сумма для таргет;
        }

        seen[current] = i; // Если не нашли пару, то добавляем текущую;
    }

    return {-1, -1};
}

int main() {
    vec nums = {2, 7, 11, 15};

    int targ = 9;

    indx_pair result = two_sum_map(nums, targ);

    std::cout << "The indices of the two elements that make up the target (" << targ << ") sum: " << result.first << ", " << result.second << std::endl;

    return 0;
}