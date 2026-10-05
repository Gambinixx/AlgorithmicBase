#include <iostream>
#include <vector>

// Оформляем инструмент в класс
class RangeSumQuery {
private: // Зона невидимости
    std::vector<int> prefix_sums;
    // Ты был прав... Самое интересное, что "управление" даже не заходит в эту зону.
public:
    // Конструктор
    RangeSumQuery(const std::vector<int>& vec) {
        int n = vec.size();

        prefix_sums.assign(n + 1, 0); // Инициализируем нулями

        // Инженерный узел
        for (int i = 0; i < n; i++) {
            // Каждый следующий элемент префиксов: это старый префикс + новый элемент
            prefix_sums[i + 1] = prefix_sums[i] + vec[i];
        }
    }

    int get_sum(int L, int R) {
        return prefix_sums[R + 1] - prefix_sums[L];
    }
};

int main() {
    std::vector<int> vec = {3, 4, 1, 2, 5, 6};

    RangeSumQuery rsq(vec); // Наш конструкт префиксов

    // Вызываем метод для отрезков
    int sum1 = rsq.get_sum(1, 3); // сумма отрезка [4, 1, 2]: 7
    int sum2 = rsq.get_sum(0, 5); // сумма отрезка [3, 4, 1, 2, 5, 6]: 21

    std::cout << "Segment 1: [4, 1, 2], sum: " << sum1 << std::endl;
    std::cout << "Segment 1: [3, 4, 1, 2, 5, 6], sum: " << sum2 << std::endl;

    return 0;
}