#include <iostream>
#include <algorithm>
#include <vector>

int const RUN = 8;

// 1. Сортировка вставками на локальном отрезке памяти [left, right]
void insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 2. Стабильное слияние двух отсортированных кусков: [l ... m] и [m+1 ... r]
void merge(int arr[], int l, int m, int r) {
    // Выводим длину из логики: Конец минус Начало + 1
    int len1 = m - l + 1;
    int len2 = r - m;

    // Создаем буферы
    std::vector<int> left(len1), right(len2);

    // Заполняем буферы (строго знак < чтобы не вылететь за границы памяти)
    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    // Пошаговое сшивание без синтаксической каши со знаками ++ внутри скобок
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Подчищаем хвосты
    while (i < len1) arr[k++] = left[i++];

    while (j < len2) arr[k++] = right[j++];
}

// Управляющий каркас Timsort
void Timsort(int arr[], int n) {
    // шаг строго равен RUN, чтобы не пропускать куски массива
    for (int i = 0; i < n; i += RUN) {
        int right_border = std::min((i + RUN - 1), (n - 1));
        insertion_sort(arr, i, right_border);
    }

    // Фаза слияния чанков
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1)); // Исправлено: std::min вместо std::mid

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main() {
     int arr[] = {
        45, 7, 22, 90, 12, 34, 64, 25,  // RUN 1
        8, 55, 19, 3, 71, 14, 88, 31,   // RUN 2
        99, 11, 4, 66, 2, 83, 50, 17,   // RUN 3
        5, 91, 13, 44, 82, 29, 60, 10   // RUN 4
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    Timsort(arr, n);

    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 8 == 0) std::cout << "| ";
    }
    std::cout << std::endl;

    return 0;
}
