#include <iostream>
#include <vector>

int remove_dupl(std::vector<int>& vec) {
    // Проверяем пустой ли вектор
    if (vec.empty()) return -1;

    // Устанавливаем указатель slow на ноль, по-умолчанию уникален.
    int slow = 0;

    // fast бежит вперёд и находит дубли
    for (int fast = 1; fast < vec.size(); fast++) {
        // отличается от уникального
        if (vec[fast] != vec[slow]) {
            // Продвигаем уникальную зону
            slow = slow + 1;
            // Продвигаем уникальный элемент
            vec[slow] = vec[fast];
        }
    }
    // Количество уникальных элементов + 1
    return slow + 1;
}

int main() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 4, 4};

    int unique_count = remove_dupl(vec);

    std::cout << "Unique items: " << unique_count << std::endl;
    std::cout << "Array after remove dupl: " << std::endl;
    for (int i = 0; i < unique_count; i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}
