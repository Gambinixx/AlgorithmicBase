#include <iostream>
#include <algorithm>
#include <cmath>

void insertion_sort(int arr[], int left, int right) {
    int n = right - left + 1;

    int* local_arr = arr + left;

    for (int i = 1; i < n; i++) {
        int key = local_arr[i];

        int j = i - 1;

        while (j >= 0 && local_arr[j] > key) {
            local_arr[j + 1] = local_arr[j];
            j--;
        }
        local_arr[j + 1] = key; // Перепутал j и i, и долго ебался не мог понять почему чанки дубликатами заполняються...
    }
}

void heapify(int arr[], int n, int i, int start) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[start + left] > arr[start + largest]) largest = left;
    if (right < n && arr[start + right] > arr[start + largest]) largest = right;

    if (largest != i) {
        std::swap(arr[start + i], arr[start + largest]);
        heapify(arr, n, largest, start);
    }
}

void heap_sort(int arr[], int start, int end) {
    int n = end - start + 1;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, start);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[start], arr[start + i]);
        
        heapify(arr, i, 0, start);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);

    // Возвращаем pivot_index;
    return i + 1;
}

void introSortUtil(int arr[], int low, int high, int depthlimit) {
    int size = high - low + 1;

    if (size <= 16) {
        insertion_sort(arr, low, high);
        return;
    }

    if (depthlimit == 0) {
        heap_sort(arr, low, high);
        return;
    }

    // Наш quick_sort
    int pivot_index = partition(arr, low, high);

    introSortUtil(arr, low, pivot_index - 1, depthlimit - 1); // Для левой стороны массива
    introSortUtil(arr, pivot_index + 1, high, depthlimit - 1); // Для правой

}

void introSort(int arr[], int n) {
    int depthlimit = 2 * std::log2(n);
    introSortUtil(arr, 0, n - 1, depthlimit);
}

int main() {
    int arr[] = {
    45, 7, 22, 90, 12, 34,
    64, 25, 8, 55, 19, 3, 
    71, 14, 88, 31, 99, 11,
    4, 66, 2, 83, 50, 17, 
    5, 91, 13, 44, 82, 29, 
    60, 10
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    introSort(arr, n);

    std::cout << "Introsort output: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 8 == 0) std::cout << "| ";
    }
    std::cout << std::endl;

    return 0;
}
