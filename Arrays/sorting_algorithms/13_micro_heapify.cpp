#include <iostream>
#include <algorithm>
#include <cmath>

// Строим пирамиду
void micro_heapify(int arr[], int n, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        micro_heapify(arr, n, largest);
    }
}

int main() {

    int arr[] = {12, 11, 13, 5, 6, 7, 1, 9, 10, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2 - 1; i >= 0; i--) micro_heapify(arr, n, i);

    std::cout << "Max-Heap пирамида: " << std::endl;
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}