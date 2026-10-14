#include <iostream>
#include <functional> // Библиотека стандартных хэш-функций
#include <cstddef>
#include <vector>

int main() {
    // Вытаскиваем стандартные хэш-чертежи для интов
    std::hash<int> hasher_int;

    std::vector<int> nums = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

    for (int num : nums) {
        std::size_t hash = hasher_int(num); // Стандартный механизм получения хэш-значения
        std::size_t bucket_index = hash % 10; // Симуляция хэш-структуры на десять бакетов

        std::cout << "data: " << num << " -> "
                  << "hash: " << hash << " -> "
                  << "bucket index: " << bucket_index
                  << " \n";
    }
}