#include <iostream>
#include <vector>
#include <utility>

class MaxHeap {
private:
    std::vector<int> heap;

    // Вспомогательные математические инлайны для процессора
    int parent(int i) const { return (i - 1) / 2; }
    int leftChild(int i) const { return 2 * i + 1; }
    int rightChild(int i) const { return 2 * i + 2; }

    // Просеивание вверх: восстанавливает инвариант кучи после вставки в конец вектора
    void siftUp(int i) {
        // Пока мы не в корне и текущий элемент больше своего родителя
        while (i > 0 && heap[i] > heap[parent(i)]) {
            // Замена значений в RAM. Локальный сдвиг элементов в векторе.
            std::swap(heap[i], heap[parent(i)]);

            // Поднимаем индекс шпиона выше по иерархии
            i = parent(i);
        }
    }

public:
    // Вставка нового значения за O(log N)
    void insert(int val) {
        heap.push_back(val);

        // Просеиваем элемент вверх, чтобы вернуть баланс сил
        siftUp(static_cast<int>(heap.size()) - 1);
    }

    // Для Watch-радаров: даем константный доступ к сырому массиву
    const std::vector<int>& getRawData() const {
        return heap;
    }
};

int main() {
    MaxHeap max_heap;

     // Хаотичный поток чисел
    max_heap.insert(10);
    max_heap.insert(20);
    max_heap.insert(5);
    max_heap.insert(30);
    max_heap.insert(15);

    // В RAM плоский вектор выстроится в структуру Max-Heap:
    // Индексы:  [0]  [1]  [2]  [3]  [4]
    // Значения: 30   20   5    10   15
    //
    // Визуальное дерево в твоей голове:
    //        30
    //       /  \
    //     20    5
    //    /  \
    //  10   15

    const auto& raw = max_heap.getRawData();

    const int current_size = static_cast<int>(raw.size());

    if (!raw.empty()) {
        std::cout << "Root element (Max): " << raw[0] << "\n";
    }

    return 0;
}