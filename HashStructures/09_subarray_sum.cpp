#include <iostream>
#include <vector>
#include <unordered_map>

using vec = std::vector<int>;

int subarray_sum(const vec& arr, int target) {

    std::unordered_map<int, int> prefix_map;

    prefix_map[0]++; // Всегда учитываем ноль, чтобы не проебывать подмассивы

    int prefix = 0;
    int subarr = 0;

    for (int num : arr) {
        
        prefix += num; // создаем префикс

        int diff = prefix - target; // разница поможет находить префикс с которого начинается подмассив размером с таргет
        if (prefix_map.find(diff) != prefix_map.end()) {
            // если префикс в хэш-мапе
            subarr += prefix_map[diff]; // увеличиваем счетчик подмассивов
        }

        prefix_map[prefix]++; // в любом случае добавляем префикс в хэш-мапу и отмечаем, что встретили
    }

    return subarr; // возвращаем количество найденных подмассивов каждый суммой равный таргет
}

int main() { 
    vec nums = {1, 2, 2, 4, 2, 2, 5}; 
    int target = 4; 
    
    std::cout << "Target sum subarrays count: " << subarray_sum(nums, target) << "\n"; 
    
    return 0; 
}