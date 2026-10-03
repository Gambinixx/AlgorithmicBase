#include <iostream>
#include <algorithm>

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Самый правый
    int i = low - 1; // за пределами меньших чисел

    for (int j = low; j < high; j++) {
        // Числа меньше Pivot — слева, числа больше — справа
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // Ставим pivot на место
    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

int main() {

    int arr[] = {64, 34, 12, 22, 11, 90, 25}; 
    int n = 7;

    int pivot_idx = partition(arr, 0, n - 1);

    std::cout << "Partition Index of Pivot: " << pivot_idx << std::endl;
    std::cout << "Array after Partition: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}