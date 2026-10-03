#include <iostream>
#include <algorithm>

void heapify(int arr[], int n, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Наша max-heap пирамида
    // Проталкиваем самый элемент тяжелый снизу-вверх. 
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Меняем мастами корень и текущий конец отрезка
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        
        // Вызываем heapify для текущего индекса ноль, но сужаем пространство
        heapify(arr, i, 0);
    }
}

int main() {

    int arr[] = {12, 11, 13, 5, 6, 7, 1, 9, 10, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--) heap_sort(arr, n);

    std::cout << "SOrted: " << std::endl;
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}