#include <iostream>
#include <algorithm>
#include <vector>

// Возвращаем vector двух индексов (сумма трагет)
std::vector<int> two_sum(std::vector<int> vec, int target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int two_sum = vec[left] + vec[right];

        if (two_sum == target) {
            return {left, right};
        }

        else if (two_sum > target) {
            right--;
        }

        else {
            left++;
        }
    }
    return {-1, -1}; // Если пара не найдена
}

int main() {
    // Для two sum важно чтобы вектор был отсортирован по возрастанию.
    std::vector<int> vec = {2, 7, 11, 15, 22, 30};

    std::vector<int> result = two_sum(vec, 26);

    std::cout << "Target sum indexes: [" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}