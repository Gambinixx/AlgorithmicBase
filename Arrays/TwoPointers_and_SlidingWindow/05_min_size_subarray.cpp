#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int min_size_subarray(std::vector<int>& vec, int target) {
    int left = 0;
    int min_size = INT_MAX;
    int current_sum = 0;

    for (int right = 0; right < vec.size(); right++) {
        current_sum += vec[right];

        while (current_sum >= target) {
            int min_sum = right - left + 1;
            min_size = std::min(min_size, min_sum);

            // Сокращаем окно слева
            current_sum -= vec[left];

            left++;
        }
    }
    return (min_size == INT_MAX) ? 0 : min_size;
}

int main() {
    // Цель target = 7. Минимальный кусок, дающий в сумме >= 7 — это чанк {4, 3} на конце. 
    // Его длина равна 2.
    std::vector<int> vec = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = min_size_subarray(vec, target);

    std::cout << "Minimum length of subarray with sum >= " << target << " is: " << result << std::endl;

    return 0;
}