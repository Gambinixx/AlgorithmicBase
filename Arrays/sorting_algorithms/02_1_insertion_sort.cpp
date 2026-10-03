// Изолированный механизм: 1
#include <iostream>
#include <algorithm>
#include <cmath>

void insertion_sort(int arr[], int left, int right) {
    int n = right - left + 1;

    // Чтобы работать с чанками большого массива, делаем локальный срез
    int* local_arr = arr + left;
    for (int i = 1; i < n; i++) {
        int key = local_arr[i];
        int j = i - 1;
        while (j >= 0 && local_arr[j] > key) {
            local_arr[j + 1] = local_arr[j];
            j--;
        }
        local_arr[j + 1] = key;
    }
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 1, 9, 10, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, 0, n - 1);

    std::cout << "Sorted Output: " << std::endl;
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}