#include <iostream>
#include <algorithm>
#include <vector>

int max_sum_subarray(std::vector<int>& vec, int k) {
    int max_sum = 0;
    int window_sum = 0;

    // Стартовое окно
    for (int i = 0; i < k; i++) {
        window_sum += vec[i];
    }

    // Начальная макс сумма
    max_sum = window_sum;

    // Скольжение. Двигаем правую границу
    for (int right = k; right < vec.size(); right++) {
        // Добавили элемент справа, вычли элемент ушедший слева
        window_sum = window_sum + vec[right] - vec[right - k];

        // Сразу проверяем на большую сумму
        max_sum = std::max(max_sum, window_sum);
    }
    
    return max_sum;
}



int main() {
    // Длина K = 3. Максимальная сумма тут прячется на отрезке {5, 6, 7} и равна 18.
    std::vector<int> vec = {2, 1, 5, 1, 3, 2, 11, 5};
    int k = 3;

    int result = max_sum_subarray(vec, k);

    std::cout << "Maximum sum of subarray of size " << k << " is: " << result << std::endl;

    return 0;
}