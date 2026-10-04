#include <iostream>
#include <algorithm>
#include <vector>

void move_zeroes(std::vector<int>& vec) {
    int slow = 0;

    for (int fast = 0; fast < vec.size(); fast++) {
        if (vec[fast] != 0) {
            // Рокировка
            std::swap(vec[slow], vec[fast]);
            // Продвигаем зону упорядоченных чисел
            slow++;
        }
    }
}

int main() {
    std::vector<int> vec = {0, 1, 0, 3, 12};

    // Настройка твоего Watch-радара при старте F5:
    // Добавь в Watch: &vec, 5
    // Добавь в Watch: slow, fast

    move_zeroes(vec);


    std::cout << "Array after moving zeroes: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}